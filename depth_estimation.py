import torch
import cv2
import numpy as np
import time
from torchvision.transforms import Compose, Normalize, Resize, ToTensor
from PIL import Image

# Load MiDaS depth estimation model
model = torch.hub.load("intel-isl/MiDaS", "MiDaS_small")
model.eval()

# Define preprocessing function
def preprocess(frame):
    transform = Compose([
        Resize((384, 384)),  # Resize to match MiDaS input
        ToTensor(),
        Normalize(mean=[0.5], std=[0.5])
    ])
    image = Image.fromarray(cv2.cvtColor(frame, cv2.COLOR_BGR2RGB))
    return transform(image).unsqueeze(0)

# Choose source: Webcam or Video
USE_WEBCAM = True  # Set to False if using a video file

if USE_WEBCAM:
    cap = cv2.VideoCapture(0)  # 0 = default webcam
else:
    video_path = "webcam.mp4"  # Replace with your actual filename
    cap = cv2.VideoCapture(video_path)

time.sleep(2)  # Allow camera to warm up

while cap.isOpened():
    ret, frame = cap.read()
    if not ret:
        print("❌ Failed to grab frame")
        break

    # Print original frame size
    print("Frame size:", frame.shape)

    # Preprocess the frame
    input_tensor = preprocess(frame)

    # Perform inference
    with torch.no_grad():
        depth_map = model(input_tensor)

    # Convert depth map to numpy
    depth_map = depth_map.squeeze().cpu().numpy()

    # Print depth map size before resizing
    print("Depth map size before resize:", depth_map.shape)

    # Normalize depth map to 0-255 for visualization
    depth_map_colored = cv2.normalize(depth_map, None, 0, 255, cv2.NORM_MINMAX, dtype=cv2.CV_8U)
    depth_map_colored = cv2.applyColorMap(depth_map_colored, cv2.COLORMAP_PLASMA)

    # Resize the depth map to match the frame size
    depth_map_colored = cv2.resize(depth_map_colored, (frame.shape[1], frame.shape[0]))

    # Print depth map size after resizing
    print("Depth map size after resize:", depth_map_colored.shape)

    # Combine original frame and depth map side by side
    combined = np.hstack((frame, depth_map_colored))
    cv2.imshow("Depth Estimation (Left: Original | Right: Depth)", combined)

    # Press 'q' to exit
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

cap.release()
cv2.destroyAllWindows()
