### Mini Project: Use SVM to Control Dinosaur Game with Motion
#### Collect Data from MPU6050
- I use the ESP32 to read accelerometer data from the MPU6050 sensor.
  ![image](https://github.com/user-attachments/assets/710f00ff-d440-4943-af21-3f01ba71db38)
- I collect 2 types of data (stand still (label=0), jump (label=1))
#### Data Processing & Visualization
- Merge the data into a single file.
- Plot a 2D graph to visualize whether the standing and jumping data are clearly separated.
  ![image](https://github.com/user-attachments/assets/9849b859-f10d-4208-92e2-2115bbd2e810)
#### Train the Model
- I use SVM or Logistic Regression to train a model to classify between “stand” and “jump”.
- After training, I get:weights, bias, mean, scale for mormalization
#### Embed the Model into ESP32
- I convert the model to pure C++ code to run on the ESP32.
![image](https://github.com/user-attachments/assets/608ad4aa-6607-4640-a6b9-8750d1f4a84b)
- Every time new data comes in, the ESP32 will: normalize the input, predict the action, if it’s “jump”, send a signal to the computer.
![image](https://github.com/user-attachments/assets/768968f8-e518-49f0-be33-2f61e4d1b7f5)
#### Control the Dinosaur Game
- I write a Python script on the computer: receive the “jump” signal from the ESP32 via Serial, Use ``pyautogui`` to press the Space key.
- Result: When I jump, the dinosaur jumps too
