import sensor
import image
import time

# Initialize the camera
sensor.reset()  # Reset the sensor
sensor.set_pixformat(sensor.GRAYSCALE)  # Use grayscale for better motion detection
sensor.set_framesize(sensor.QQVGA)  # Set frame size to QQVGA (160x120)
sensor.skip_frames(time=2000)  # Let the camera initialize for 2 seconds
sensor.set_auto_gain(False)  # Disable automatic gain for consistent lighting
sensor.set_auto_whitebal(False)  # Disable automatic white balance
sensor.set_vflip(True)

print("Initializing...")
time.sleep(1)

# Capture the first reference frame
print("Capturing first image...")
reference_frame = sensor.snapshot().copy()  # Save the first frame as a reference
print("First image captured!")

# Countdown before starting motion detection
for i in range(5, 0, -1):
    print(f"Starting motion detection in {i} seconds...")
    time.sleep(1)

# Start motion detection
print("Motion detection started!")
while True:
    img = sensor.snapshot()  # Capture a new frame
    diff = img.difference(reference_frame)  # Compute the difference with the reference frame

    # Find moving objects (blobs) in the difference image
    blobs = diff.find_blobs([(20, 255)], pixels_threshold=20, area_threshold=20)

    for blob in blobs:
        # Draw a rectangle around the detected motion
        img.draw_rectangle(blob.rect(), color=(255, 255, 255))
        img.draw_cross(blob.cx(), blob.cy(), color=(255, 255, 255))

    # Display the frame (with rectangles drawn)
    print("Motion detected!" if blobs else "No motion.")
