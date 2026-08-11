# Soft Robotics Myoelectric Transradial Prosthesis

Open-source repository for the undergraduate thesis **“Soft Robotics Prototype of a Transradial Myoelectric Prosthesis”**, developed by **Mariana Toro Ramírez** and **María Alejandra Mejía Ramírez** as part of the B.Sc. in Mechatronics Engineering at Universidad EIA, under the supervision of Prof. David Rozo Osorio.

## About the Project

This project focused on the design, development, and evaluation of a functional prototype of a transradial myoelectric prosthesis using soft-robotics principles.

The prosthesis integrates mechanical, electronic, signal-processing, and control systems into a single prototype. Its mechanical design uses cable-driven, underactuated mechanisms and flexible structures to reproduce selected movements of the human hand while reducing mechanical and control complexity. The system captures electromyographic (EMG) signals from the user, conditions and digitizes these signals, and processes them through an embedded control system to identify the user's intended action and actuate the prosthetic hand accordingly.

The prototype was designed to perform four common grasp types while incorporating considerations of functionality, ergonomics, robustness, manufacturability, and accessibility. Particular attention was given to the Colombian context and to the potential of rapid-manufacturing and open-source approaches to contribute to the development of more accessible upper-limb prosthetic technologies.

## Repository Contents

This repository contains the files generated throughout the design and development of the prosthesis, including:

- **Mechanical design:** CAD models and files for the socket, palm, fingers, thumb mechanism, and prosthesis assembly.
- **Electronic design:** schematics and PCB design files for the two-channel EMG acquisition and conditioning system, including integration of the MCP3561 analog-to-digital converter and ESP32 microcontroller.
- **PCB manufacturing:** files required for fabrication and assembly of the electronic board, including manufacturing-related documentation.
- **Signal processing and embedded control:** source code for EMG signal acquisition and processing, ADC configuration, grasp classification, and motor control.
- **Simulation files:** electronic simulations used during the design and validation of the EMG signal-conditioning circuitry.

The repository was created as an open-source resource to facilitate the continuation, reproduction, and further development of the project.

## Abstract

This research focuses on the development of a prototype of a transradial myoelectric prosthesis using soft robotics technology for amputated limbs. The relevance of the development focuses on the need to improve the quality of life of the amputated people, highlighting the importance of generating a functional and ergonomic product, mainly framed in the Colombian society and context. The analysis of the current state of the art precedes a detailed description of the adopted methodology. Preliminary research focuses on key aspects such as hand biomechanics and a review of the most recent advances in the field of prosthetics, with emphasis on the use of underactuated transmission and coupled motion architectures. An EMG circuit capable of capturing myoelectric signals, allowing for adaptability to different users and muscles is designed; also, a mechanical design is developed that includes the construction of a socket, palm, and fingers, following the anthropometric characteristics of a mature female user, actuated by cables, which allows performing the movements of abduction and adduction of the thumb, and exion and extension of all fingers, allowing to execute four types of grasps that statistically an average user executes most frequently in their daily activities. A myoelectric control algorithm is developed, which identifies, classifies, and executes the grasps on the user’s demand. Optimization of
the control code and improvements in the mechanical system are suggested for future research. Finally, it is concluded that the project has achieved its objectives in terms of functionality and performance.

**Keywords:** Soft Robotics, Transradial Prosthesis, Myoelectric Signal, EMG.

## Thesis

The complete thesis is available through the Universidad EIA institutional repository:

**Toro Ramírez, M., & Mejía Ramírez, M. A. (2023). _Prototipo en robótica suave de prótesis mioeléctrica transradial_. Universidad EIA.**

https://repository.eia.edu.co/handle/11190/6398


## Authors

**Mariana Toro Ramírez**  
B.Sc. Mechatronics Engineering, Universidad EIA

**María Alejandra Mejía Ramírez**  
B.Sc. Mechatronics Engineering, Universidad EIA

## Thesis Supervisor

**Prof. David Rozo Osorio**
MEng. Mechatronics, Robotics and Automation Engineering, Universidad Pontificia Bolivariana




![WhatsApp Image 2023-10-22 at 08 35 48](https://github.com/MarianaToroR/Soft_Robotics_Myolectric_Transradial_Prosthesis/assets/148642102/b56f1b4f-22a9-4df2-b1c7-a4bef21d64b6)
