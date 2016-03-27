# Course annotation

I. Preliminaries

1. Introduction (Theory) N
  1. Why game development?
  1. Differences in building games and other software (C++ vs HL Languages, budget, deadlines, overtime, team)
  1. Game Engine Survey
  1. Why Unreal and why not U3D?
  1. Tools of the trade - VS, source control (list of other tools? - profilers, debuggers)

1. Introduction (UE4) Epic Games
  1. Downloading and installing UE4. Git and VS.
  1. Trying out the samples
  1. Directory structure
  1. Important modules
  1. Creating Hello, UE4.

2. Fundamentals (Theory) D
  1. C++ Review and Best Practices (smart pointers, iterators, error handling, libraries, unity builds)
  1. Pipelines, Caches and Optimization
  1. Tools support

2. Fundamentals (UE4) N
  1. UE4 Editor.
  1. UHT, UBT, UE4's modular approach
  1. UE4 naming convention - U vs A vs S vs T vs F
  1. Blueprint scripting (needed to make things easier)

3. 3D Math for Games (Theory) N
  1. Points and Vectors
  1. Matrices
  1. Quaternions
  1. Comparison of Rotational Representations
  1. SIMD

3. 3D Math for Games (UE4) N
  1. Common classes for math-related operations - FVector, FMatrix, FQuat.
  1. Solving common problems - collision detection, intersections, getting things to move the way we want them to.

4. Architecturing games (Theory) SN
  1. Game loop. Delta timing.
  1. Rendering algorithms. Z-index vs Raycasting.
  1. Subsystems. Subsystem updates.
  1. Game Objects.
  1. Breaking the world into levels.

4. Architecturing games (UE4) SN
  1. Basic UE4 classes - AGameMode & APlayerController. UObject, AActor.
  1. Ticking. Interaction between classes. Break down of the FPS Demo game.
  1. Exercises to make changes to the FPS game.
  
II Low-Level Engine Systems

5. Engine Support Systems (Theory) DT
  1. Standard library. Why does everyone roll an STL of their own?
  1. Subsystem Start-Up and Shut-Down.
  1. Memory Management. Allocators.
  1. Resources and the File System. (cooking and baking content)
  1. Engine Configuration.

5. Engine Support Systems (UE4) DT
  1. UE4 Standard Library (FString, TArray, TMap, etc.)
  1. Garbage Collection. RTTI. Serialization
  1. UAssets. Cooking content.
  1. Engine Configuration. Config files, Config classes.

6. Tools for Debugging and Development (Theory) D
  1. Logging and Tracing. Asserts. Crash Reporting.
  2. Debug Drawing Facilities
  4. In-Game Console
  5. Debug Cameras and Pausing the Game
  8. Profiling - sequential vs sampling profilers
  9. Memory tracking and leaks
  10. Testing

6. Tools for debugging and development (UE4) N
  1. UE4_Log. Declaring different log categories. Assertions.
  1. Breakpoints in CPP and BP.
  1. Console
  1. Debug cameras, pausing, ejecting / possessing.
  1. UE4 session frontend. Profiling, Automation.

7. The Rendering Engine (Theory) S?
  1. Foundations of Depth-Buffered Triangle Rasterization. Fancy words (Textures, Materials, AA, VSync..)
  1. The Rendering Pipeline
  1. Advanced Lighting and Global Illumination
  1. Visual Effects and Overlays
  1. GPU Debugging tools.
  1. HLSL?

7. The Rendering Engine (UE4) AS
  1. Controlling the rendering pipeline, setting the settings.
  1. RHI rendering.
  1. Rolling your own shaders.

III. Advanced systems

8. Animation Systems (Theory) Oberon? 
  1. Morph Targets Vs. Skinning
  1. Skeletons
  1. Poses and Clips
  1. Animation Blending
  1. Inverse Kinematics
  1. Action State Machines

8. Animation Systems (UE4) Oberon?
  1. Getting and creating models. 3D design tools (3DS, Maya, ZBrush)
  1. Importing models. Morph targets and skinned.
  1. Persona overview.

9. Physics (Theory) N
  1. Physics capabilities Vs. performance / engineering hit. Do we always need physics?
  1. Available Middleware
  1. The Collision Detection System.
    1. Physics world
    1. Broadphase.
    1. Primitive shapes (AABB, Spheres, Capsules)
    1. Algorithms for intersection and contact generation
    1. Collision filtering
    1. Collision queries & raycasting
  1. Rigid Body Dynamics - Velocities, Impulses, Integration methods, Constraints
  1. Integrating a Physics Engine into Your Game - Fixed time steps, Multithreading
     http://gafferongames.com/game-physics/fix-your-timestep/

9. Physics (UE4) N
  1. Collision detection. Collision responses.
  1. Physics materials.
  1. Constraints.
  1. Vehicles?

10. UI (MWAHAHAHAHAHAA, time for shameless advertisement) (Theory) SN
  1. Requirements of an UI system
    1. Time to develop
    1. Iteration time
    1. Available content-creation tools
    1. Advanced UI features
      1. Scripting
      1. Animations
      1. Video and audio (+ transparency)
      1. Live views
      1. Localisation and IME
    1. Source control
    1. Performance requirements
  1. UI technologies - own implementation vs. HTML5 vs. Flash
  1. Available middleware (Coherent, Scaleform, UMG)

10. UI (UE4) N
  1. Slate
  1. UMG
  1. Integrating Coherent in UE4

11. Audio (Theory) N
  1. The Physics of Sound
  1. Rendering Audio in 3D
  1. Audio formats
  1. Available Middleware

11. Audio (UE4) N
  1. Creating and importing audio files. Audacity.
  1. Sound cues.
  1. Attenuation

12. AI (Theory) N
  1. Pathfinding in graphs. A*.
  1. Problems with graphs:
    1. Movement on railtracks
    1. Number of nodes.
  1. Navigation meshes. Path smoothing.
  1. State machine agents.

12. AI (UE4) N
  1. Behaviour trees
  1. Environment Query System
  1. Sample maze runner

13. Networking (Theory) http://gafferongames.com/networking-for-game-programmers/ D
  1. UDP over TCP
  1. Building a custom protocol
  1. Client-side prediction and Server Reconciliation

13. Networking (UE4) D
  1. Replication
  1. Controlling replication and function calls.
  1. Building and running a dedicated server.
  1. Multiplayer travelling.

14. Miscellaneous (Theory) D
  1. Embedding a scripting system - Lua vs Python vs JS vs BP.
  1. Cinematics
  1. ???

14. Plugins (UE4) N
  1. Game plugins vs engine plugins
  1. Anatomy of a plugin. Directory structure.
  1. Implementing and using a plugin. Distribution.

# Grading:

1. 2 Tests
  * 25 - 30 questions
  * 15% each of total grade.
1. 2 Homeworks
  * Mini-projects, might take between 5 and 10 hours
  * 20% each of the total grade
1. Course project
  * 30% of total grade.
  * 15% for execution, 15% for code quality
  * Students are free to choose it.
  * Ideas must be accepted by the teaching team before the project's development
