# Physics

## Q: Definition of dot product?
- A: $\angle pq = \arccos{ \frac {p \cdot q}{|p||q|}}$

## Q: How to compute a surface normal?
- A: $N = p \times q$, where $p$ and $q$ define the surface.

## Q: Pros and cons of Euler angles?
- A: Useful for humans, terrible for code.

## Q: Use of rotation matrices?
- A: Best for concatenating transforms, memory inefficient.

## Q: Why and how change coordinate system?
- A: Simplifies tasks like rotation; use matrix from target system's origin and axes.

## Q: Physics in game design?
- A: Focus on enjoyment over realism.

## Q: Main purposes of physics in games?
- A: Destruction, rag-dolls, machinery, dangling animations.

## Q: Complications with physics in game design?
- A: Predictability, tuning, emergent behaviour, artist and designer friendliness.

## Q: Middleware solutions for physics?
- A: PhysX, Havok, Open Dynamics Engine, Bullet.

## Q: Difference between physics and collision?
- A: Collision for detecting contacts, physics for movement.

## Q: World separation in game physics?
- A: Separate game world and physics world, each entity has a physics identifier.

## Q: Collision system main tasks?
- A: Detect collisions, report data (contact point, vector), collision queries.

## Q: Primitives for collision?
- A: Spheres, capsules, boxes (AABB & OBB), tetrahedrons, convex/concave shapes.

## Q: Sphere collision check formula?
- A: $\|K_2 - K_1\|^2 \leq (r_1 + r_2)^2$

## Q: Separating axis theorem application?
- A: Disjoint convex sets A and B do not overlap along axis a.

## Q: AABB collision condition?
- A: $\text{min}\_{1_x} \leq \text{max}\_{2_x} \land \text{min}\_{2_x} \leq \text{max}\_{1_x} \land \text{min}\_{1_y} \leq \text{max}\_{2_y} \land \text{min}\_{2_y} \leq \text{max}\_{1_y} \land \text{min}\_{1_z} \leq \text{max}\_{2_z} \land \text{min}\_{2_z} \leq \text{max}\_{1_z}$

## Q: AABB collision check code?
- A: 
```cpp
bool intersects = b1.min.x < b2.max.x && b2.min.x < b1.max.x &&
                  b1.min.y < b2.max.y && b2.min.y < b1.max.y &&
                  b1.min.z < b2.max.z && b2.min.z < b1.max.z;
```

## Q: Convex vs. concave?
- A: Convex: no segment outside shape. Concave: violates convex rules.

## Q: Contact point calculation for line and sphere?
- A: Solve $\|M + p \mu - O\| = r$ for $\mu$.

## Q: Collision queries types?
- A: Ray casting, shape casting, phantoms, closest-point.

## Q: Collision filtering methods?
- A: Channels/layers, callbacks.

## Q: Performance optimization in collision?
- A: Spatial partitioning, temporal coherency, broad/mid/narrow phases.

## Q: Newtonian rigid body dynamics focus?
- A: Position & rotation in Newtonian world.

## Q: Units for Newtonian dynamics?
- A: Kilogram, meter, second (KMS).

## Q: Linear dynamics gives?
- A: Solution to function $\mathbf{S}(t)$, position at time $t$.

## Q: Newton's second law equation?
- A: $\mathbf{F_{net}} = m\mathbf{a}(t)$, if mass is constant.

## Q: Equation for numerical integration?
- A: $\mathbf{v}(t + \Delta t) = \mathbf{v}(t) + \mathbf{a}(t) \Delta t$

## Q: Properties of integrators?
- A: Convergence, stability, order.

## Q: Example of integrators?
- A: Explicit Euler, Verlet, Runge-Kutta 4 (RK4).

## Q: Collision response conservation?
- A: Energy conservation: $\mathbf{p}_1 + \mathbf{p}_2 = \mathbf{p'}_1 + \mathbf{p'}_2$

## Q: Physics engine bodies classification?
- A: Fixed, game-driven, physics-driven bodies.

## Q: Physics material properties?
- A: Elasticity, friction, bounce, stickiness, density.

## Q: Basic algorithm for object position from forces?
- A: $\mathbf{a}(t) = \frac{\mathbf{F_{net}}}{m}, \mathbf{v}(t + \Delta t) = \mathbf{v}(t) + \mathbf{a}(t) \Delta t, \mathbf{S}(t + \Delta t) = \mathbf{S}(t) + \mathbf{v}(t) \Delta t$

## Q: Why is TIME_STEP constant?
- A: For stability in physics simulation.

# Graphics 1

## Q: What composes a 3D scene?
- A: Geometries, lights, materials, objects, camera.

## Q: Essential for geometry in 3D?
- A: Equations, NURBS, subdivision, triangle meshes.

## Q: Importance of triangles in 3D?
- A: Always planar, remain under transformations, basis for graphics hardware.

## Q: Role of lights in a scene?
- A: Determines visibility and ambiance.

## Q: Types of lights in 3D rendering?
- A: Directional, point, spot, area, emissive, environment.

## Q: Function defining material interaction with light?
- A: BRDF - Bidirectional Reflectance Distribution Function.

## Q: Aspect ratio's effect in rendering?
- A: Determines the shape of the displayed image.

## Q: FOV impact in rendering?
- A: Determines how wide the scene is viewed.

## Q: Rendering equation summary?
- A: Accounts for emitted light and reflected light across surfaces.

## Q: Key types of global illumination effects?
- A: Direct light, bounced light, ambient occlusion.

## Q: Painter's algorithm purpose?
- A: Simple method to handle visibility by drawing from back to front.

## Q: Ray tracing role in rendering?
- A: Simulates light paths for realistic effects, used for offline rendering.

## Q: Z-Buffer's function?
- A: Solves visibility by storing depth information for each pixel.

## Q: Use of textures in 3D models?
- A: Assigns material properties to meshes.

## Q: Mipmapping's benefit?
- A: Reduces aliasing and improves performance by using resolution-appropriate textures.

## Q: Forward vs Deferred Rendering?
- A: Forward applies lighting per object; Deferred defers lighting to a second pass using a G-Buffer.

## Q: Importance of shadow maps?
- A: Adds depth and realism through the simulation of shadows.

## Q: Role of LOD in rendering?
- A: Reduces detail for distant objects to improve performance.

## Q: Anti-aliasing methods?
- A: MSAA, FXAA, TAA - reduce visual artifacts at edges.

## Q: Post-processing effects in rendering?
- A: Enhances final image with effects like HDR, bloom, motion blur.

## Graphics 2

## Q: How does rasterization work?
- A: Goes through all geometry one by one and draws it using the graphics pipeline, utilizing Z-Buffer for depth.

## Q: What is BRDF?
- A: $f_{r}(\mathbf x, \omega_{i}, \omega_{o})$, defines how light is reflected from incoming to outgoing direction.

## Q: Data stored in G-Buffer examples?
- A: Normal, Diffuse Color, Roughness.

## Q: Briefly, how does the GPU pipeline work?
- A: Processes geometry, applies shaders, and performs rasterization to convert 3D scenes into 2D images.

## Q: Key components of GPU architecture?
- A: ALU for compute, Fetch for instruction stream, Execution context for program state, and high throughput design.

## Q: What does a GPU stall indicate?
- A: Occurs when ALU units must wait for data, showing a bottleneck in processing efficiency.

## Q: Strategy to hide GPU stalls?
- A: Saturate GPU with work, issuing multiple data requests to ensure continuous execution despite initial delays.

## Q: Ideal register usage per shader for optimal GPU performance?
- A: Less than 24 registers per shader is ideal for efficiency on AMD(GCN) architecture.

## Q: Importance of GPU bandwidth?
- A: Critical for performance, requiring data to be tightly packed and reused across computing elements.

## Q: Key graphic blocks in GPU?
- A: Rasterizer, Tessellator, HiZ/Cull Depth for pixel processing, and specialized cores like RT and Tensor Cores for ray tracing and machine learning operations.

## Q: Graphics device initialization process?
- A: Initialize the device, create swap chain, Direct3D device, and context.

## Q: How to create a texture resource?
- A: Define texture properties, call CreateTexture2D with description and initialization data.

## Q: Process for binding shader resources and shaders?
- A: Bind textures to pixel shader, set vertex and pixel shaders using context.

## Q: Drawing command in graphics API?
- A: Set primitive topology, then call DrawIndexed with indices count.

## Q: HLSL structure for vertex shader input?
- A: Define structure with position, normal, and texture coordinates.

## Q: How to perform operations in a vertex shader?
- A: Apply transformations to position, calculate world position and normals.

## Q: Key considerations for DirectX 12/Vulkan compared to older APIs?
- A: More verbose, multithreaded by design, closer control over memory and execution.

## Q: Process of submitting work to GPU?
- A: Simulate objects, determine visibility, generate and perform GPU commands, display results.

## Q: How to handle static and dynamic objects in graphics data?
- A: Organize objects into lists by type, update dynamic objects each frame, separate graphic from gameplay data.

## Q: Strategy for visibility determination in rendering?
- A: Use frustum culling, small object culling, LOD selection, and SIMD operations for efficiency.

## Q: Role of render graph in modern rendering engines?
- A: Manages memory usage, resource transitions, simplifies code, and controls render passes dynamically.

# Rendering UE

## Q: What does RHI stand for in Unreal?
- A: Rendering Hardware Interface

## Q: Purpose of `FRHICommandList`?
- A: Enqueues commands for the RHI thread

## Q: What is HLSL used for in Unreal?
- A: Writing shaders

## Q: Role of RenderCore in Unreal?
- A: Manages rendering and RHI threads, provides key utilities

## Q: How does Unreal handle game and rendering thread synchronization?
- A: Using `FRenderCommandFence` for synchronization

## Q: Key components of Physically Based Rendering (PBR) in Unreal?
- A: Base Color, Roughness, Metallic, Specular

## Q: What is Lightmass in Unreal?
- A: Unreal's lighting baking tool

# Animation

## Q: Use of skinned animations?
- A: Deforms character meshes for realistic animations.

## Q: Definition of animation clips?
- A: Sequences of poses for character animation.

## Q: What's a T-pose?
- A: Default pose for binding skeletons to meshes.

## Q: Local vs global poses?
- A: Local in joint-space, global in model-space.

## Q: Converting local to global time in animations?
- A: Use playback rate and duration for conversion.

## Q: Advantages of animation timelines?
- A: Facilitates synchronization and blending.

## Q: Formula for blending animations?
- A: $\beta = \frac{t - t_1}{t_2 - t_1}, P_{result} = lerp(P_A, P_B, \beta)$

## Q: Implementing crossfading in animations?
- A: Gradually change $\beta$ to blend animations.

## Q: What's additive blending?
- A: Combines differences between poses for final pose.

## Q: Techniques for animation data compression?
- A: Channel omission, quantization, curve fitting.

## Q: What are metachannels in animations?
- A: Additional data like texture coordinates, event triggers.

## Q: Control of animation runtime pipeline?
- A: State machines for blending and transitions based on conditions.

# Animation UE

## Q: Purpose of Persona in UE?
- A: Edits animations, blending, IK, model attachments.

## Q: Skeletal mesh creation pipeline in UE?
- A: Create mesh and skeleton, bind skin, export and import as .fbx.

## Q: Animation creation pipeline in UE?
- A: Animate skeleton, export and import animation as .fbx.

## Q: Morph target creation pipeline in UE?
- A: Create and modify mesh, export, import into UE.

## Q: Role of skeletal mesh in UE?
- A: Sets materials, clothing, LOD; maps to USkeletalMesh.

## Q: Function of sockets in UE skeleton?
- A: Attach items to skeleton statically or dynamically.

## Q: Features of animation sequence in UE?
- A: Single clip, supports events, curves, additive blending.

## Q: Concept of animation montage in UE?
- A: Composed of other animations, categorized into sections and slots.

## Q: Use of blend space in UE?
- A: For multidimensional blending, supports multiple samples.

## Q: Function of action-state machine in UE?
- A: Controls animation transitions, outputs poses based on inputs.

## Q: Components of animation blueprint in UE?
- A: Splits into AnimGraph for pose computation and EventGraph for logic.

## Q: Purpose of animation retargeting in UE?
- A: Allows use of same skeleton with different meshes.

# Networking

## Q: TCP vs. UDP?
- A: TCP: reliable, ordered; UDP: fast, unreliable.

## Q: What is RUDP?
- A: Reliable UDP, combines speed of UDP with reliability features.

## Q: Main advantages of TCP?
- A: Reliable data transmission.

## Q: Main drawbacks of TCP?
- A: Slower, consumes more resources.

## Q: Advantages of using UDP?
- A: Faster, more efficient data transmission.

## Q: Disadvantages of UDP?
- A: Lacks built-in reliability, ordering.

## Q: RUDP use cases?
- A: Real-time applications needing both speed and some reliability.

## Q: TCP vs UDP differences?
- A: TCP: reliable; UDP: faster, less reliable.

## Q: Role of HTTP in games?
- A: Handles non-critical data transmission where TCP's reliability is preferred.

## Q: Benefits of peer-to-peer networking?
- A: Cost-efficient, suitable for voice streaming and LAN parties.

## Q: What does STUN do?
- A: Discovers public IP and NAT-assigned port for P2P networking.

## Q: Client-server model advantages?
- A: Reduces cheating, simplifies development.

## Q: Purpose of data serialization in networking?
- A: Converts objects to/from network-transmittable formats.

## Q: Importance of automatic serialization?
- A: Reduces errors and automates conversion process.

## Q: What is RPC in networking?
- A: Executes procedures on another machine as if local.

## Q: How is data synchronization achieved in games?
- A: By sending only changed object properties to reduce data.

# Networking UE

## Q: What controls character movement via animations in Unreal?
- A: Root Motion.

## Q: What enables multidimensional animation blending in Unreal?
- A: Blend Space.

## Q: How does Unreal distinguish authoritative instances?
- A: ENetRole with roles like ROLE_Authority.

## Q: What method determines actor updates relevance in Unreal?
- A: AActor::IsNetRelevantFor.

## Q: How does Unreal prioritize network actor updates?
- A: AActor::GetNetPriority() and replication settings.

## Q: What term describes network synchronization in Unreal?
- A: Replication.

## Q: How to get notified on replicated property change in Unreal?
- A: RepNotify with OnRep_<PropertyName> function.

## Q: How is component replication achieved in Unreal?
- A: SetIsReplicated(true) on component.

## Q: What's conditional replication's purpose in Unreal?
- A: Selective replication, e.g., COND_OwnerOnly.

## Q: Types of RPC in Unreal Engine and distinctions?
- A: Server, Client, NetMulticast; Server requires WithValidation.

## Q: Classes defining game's rules and player interaction in Unreal?
- A: AGameMode and APlayerController.

## Q: What's level travelling in Unreal?
- A: Changing levels or maps, Seamless or Nonseamless.

## Q: Which class manages network channels in Unreal?
- A: UNetDriver.

## Q: How to optimize network traffic in Unreal games?
- A: Adjust replication, relevancy, priority, and NetUpdateFrequency.

# Networking

## Q: Network model in UE?
- Client-server.

## Q: Animation control in UE?
- Root Motion, Blend Space.

## Q: Network roles in UE?
- Authority, SimulatedProxy, AutonomousProxy.

## Q: Actor update priority in UE?
- Based on GetNetPriority().

## Q: Replication notification in UE?
- RepNotify.

## Q: Conditional replication in UE?
- Selective based on conditions.

## Q: RPC types in UE?
- Server, Client, NetMulticast.

## Q: Level travelling types in UE?
- Seamless, Nonseamless.

## Q: UE class for network management?
- UNetDriver.

## Q: Optimizing network traffic in UE?
- Adjust replication settings.

# AI

## Q: Function of APawn in Unreal Engine?
- A: Actor for player control or AI, can receive input.

## Q: Difference between ACharacter and APawn?
- A: ACharacter adds movement, collision, and visual components to APawn.

## Q: Role of AController in Unreal Engine?
- A: Directs a Pawn's actions, can be player-driven or AI-driven.

## Q: Unreal Engine's pathfinding method?
- A: Navigation meshes (navmeshes) managed by Recast & Detour.

## Q: What is a reflex agent in game AI?
- A: Acts based on current situation without planning.

## Q: How do behavior trees function in Unreal Engine?
- A: Event-driven structures defining AI logic through selectors, sequences, and parallel tasks.

## Q: Unreal Engine's AI Perception system components?
- A: Damage, Hearing, Prediction, Sight, Team, Touch.

## Q: Crowd control components in Unreal Engine?
- A: ADetourCrowdAIController, AGridPathAIController.

## Q: Machine-learning applications in Unreal Engine?
- A: Not built-in, implemented through scripting for content generation.

# Tools UE

## Q: Unreal Automation Tool framework tests
- A: Unit, integration, smoke, stress, screenshot comparison

## Q: Simple test macro in Unreal
- A: IMPLEMENT_SIMPLE_AUTOMATION_TEST

## Q: Complex test macro in Unreal
- A: IMPLEMENT_COMPLEX_AUTOMATION_TEST

## Q: Creating log category
- A: DECLARE_LOG_CATEGORY_EXTERN, DEFINE_LOG_CATEGORY

## Q: Logging severity levels
- A: Fatal, Error, Warning, Display, Log, Verbose, VeryVerbose

## Q: Visual logging in Unreal
- A: Window -> Developer Tools -> Visual Logger

## Q: Crash report storage
- A: /Saved/Crashes/ in editor, %APPDATA%/Microsoft/Windows/WER/ReportQueue in cooked build

## Q: GPU debugging tools
- A: Wireframe (F1), Disable lightning (F2), Normal render (F3), Rendering visualizers

## Q: Debug drawing helper
- A: DrawDebugHelpers.h

## Q: Screen capture commands
- A: Shot, HighResShot

## Q: Time control in Unreal
- A: TimeDilation, SetPause

## Q: In-game console custom function hook
- A: UFUNCTION(exec)

## Q: Profiling commands for CPU bound
- A: stat slow, stat unitgraph, stat Memory, stat Threads

## Q: Profiling GPU performance
- A: profilegpu

## Q: Additional Unreal tools
- A: Gameplay Debugger, Network profiler, Symbol Debugger, Class Viewer, Collision Analyzer, Widget Reflector

# UI

## Q: Slate key features
- A: Declarative syntax, extends easily, data-driven

## Q: UMG key features
- A: WYSIWYG editor, world space UI, animations, Rich Text

## Q: UMG widget state types
- A: Normal, Hovered, Pressed, Disabled

## Q: Anchors use in UMG
- A: Defines UI object position for varying resolutions

## Q: DPI Scaling strategies in UMG
- A: Shortest Side, Longest Side, Horizontal, Vertical

## Q: Custom UMG widget creation
- A: Derive from UWidget, override RebuildWidget and SynchronizeProperties

## Q: BLUI main component
- A: Chromium-based HTML engine for UE

## Q: Coherent GT feature
- A: High-performance HTML UI engine

## Q: What's immediate UI vs. retained mode UI?
- A: Immediate UI redraws every frame, retained mode UI maintains state.

## Q: Algorithms for drawing text?
- A: Rasterization, SDF.

## Q: What are l10n and i18n?
- A: Localization, internationalization.

