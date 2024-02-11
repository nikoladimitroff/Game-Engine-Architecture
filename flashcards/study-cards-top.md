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

# Tools UE

## Q: Unreal Automation Tool framework tests
- A: Unit, integration, smoke, stress, screenshot comparison.

## Q: Simple test macro in Unreal
- A: IMPLEMENT_SIMPLE_AUTOMATION_TEST.

## Q: Creating log category
- A: DECLARE_LOG_CATEGORY_EXTERN, DEFINE_LOG_CATEGORY.

## Q: Visual logging in Unreal
- A: Window -> Developer Tools -> Visual Logger.

## Q: GPU debugging tools
- A: Wireframe (F1), Disable lightning (F2), Normal render (F3), Rendering visualizers.

# UI

## Q: Slate key features
- A: Declarative syntax, extends easily, data-driven.

## Q: UMG key features
- A: WYSIWYG editor, world space UI, animations, Rich Text.

## Q: Anchors use in UMG
- A: Defines UI object position for varying resolutions.

## Q: DPI Scaling strategies in UMG
- A: Shortest Side, Longest Side, Horizontal, Vertical.

## Q: Custom UMG widget creation
- A: Derive from UWidget, override RebuildWidget and SynchronizeProperties.
