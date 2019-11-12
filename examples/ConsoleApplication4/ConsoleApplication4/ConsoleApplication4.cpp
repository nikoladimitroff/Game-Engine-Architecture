// ConsoleApplication4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <ppl.h>
#include <concrt.h>
#include <unordered_map>

struct float4x4
{
	float m_r[4][4];
};

struct float3
{
	float m_x;
	float m_y;
	float m_z;
};

struct aabb
{
	float3 m_min;
	float3 m_max;
};

enum RenderObjectType
{
	Tree		= 0,
	Chacracter	= 1,
	SkinnedTree = 2
};

static const uint32_t FeatureRenderCount = 2;

struct GameObject;

struct RenderObject
{
	uint32_t	m_type = 0;
	uint64_t	m_renderer_handle[FeatureRenderCount] = {};
	uint64_t	m_visibility_handle = 0;
	GameObject* m_go = nullptr;
};

struct GameObject
{
	std::unique_ptr<RenderObject> m_ro;
};

struct SimpleGameObject : GameObject
{
	float4x4	m_transform;
};

struct SkinnedGameObject : SimpleGameObject
{
	float4x4	m_bones[256];

	void update()
	{
		//Update bones
		//Update transform
	}
};

struct SkinnedRendererFeatures
{
	enum Renderer
	{
		Index = 0
	};

	static constexpr size_t frame_packet_size(){ return 16; }
	static constexpr size_t view_packet_size() { return 16; }

	std::vector<RenderObject*> m_ro;
};

struct TreeRendererFeatures
{
	enum Renderer
	{
		Index = 1
	};

	static constexpr size_t frame_packet_size() { return 16; }
	static constexpr size_t view_packet_size() { return 16; }

	std::vector<RenderObject*> m_ro;
};

struct RendererFeatures
{
	SkinnedRendererFeatures		m_skinned;	//Holds SkinnedGameObjects
	TreeRendererFeatures		m_trees;	//Holds SimpleGameObjects
};

struct VisibibilityWorld
{
	std::vector<RenderObject*>	m_updated_per_frame;
	std::vector<aabb>			m_updated_per_frame_aabb;

	std::vector<RenderObject*>	m_static;
	std::vector<aabb>			m_static_aabb;
};

//Data Driven
struct Character : SkinnedGameObject
{
	VisibibilityWorld* m_vo;

	void Register(RendererFeatures* r, VisibibilityWorld* vo)
	{
		m_ro		 = std::make_unique<RenderObject>();
		m_ro->m_go	 = this;
		r->m_skinned.m_ro.push_back(m_ro.get());
		m_ro->m_renderer_handle[SkinnedRendererFeatures::Index] = r->m_skinned.m_ro.size() - 1;

		//simulate initial
		vo->m_updated_per_frame.push_back(m_ro.get());
		vo->m_updated_per_frame_aabb.push_back(aabb());

		m_ro->m_visibility_handle	= vo->m_updated_per_frame.size()-1;
		m_vo						= vo;
	}

	void UnRegister()
	{
		//free
	}

	void update()
	{
		//Update bones
		//Update transform
		m_vo->m_updated_per_frame_aabb[m_ro->m_visibility_handle] = aabb();
	}
};

//Data Driven
struct Tree : SimpleGameObject
{
	VisibibilityWorld* m_vo;

	void Register(RendererFeatures* r, VisibibilityWorld* vo)
	{
		//Register in the feature renderer, store handle back, it is readonly
		m_ro = std::make_unique<RenderObject>();
		m_ro->m_type = RenderObjectType::Tree;
		m_ro->m_go = this;
		r->m_trees.m_ro.push_back(m_ro.get());
		m_ro->m_renderer_handle[TreeRendererFeatures::Index] = r->m_trees.m_ro.size() - 1;

		//simulate initial
		vo->m_static.push_back(m_ro.get());
		vo->m_static_aabb.push_back(aabb());

		m_ro->m_visibility_handle = vo->m_static.size() - 1;
		m_vo = vo;
	}

	void UnRegister()
	{
		//free
	}
};

//Data Driven
struct SkinnedTree : SkinnedGameObject
{
	void Register(RendererFeatures* r, VisibibilityWorld* vo)
	{
		//In two systems, register in the feature renderers
		m_ro = std::make_unique<RenderObject>();
		r->m_trees.m_ro.push_back(GameObject::m_ro.get());
		r->m_skinned.m_ro.push_back(SkinnedGameObject::m_ro.get());

		m_ro->m_renderer_handle[TreeRendererFeatures::Index] = r->m_trees.m_ro.size() - 1;
		m_ro->m_renderer_handle[SkinnedRendererFeatures::Index] = r->m_skinned.m_ro.size() - 1;

		m_ro->m_go		= this;
		m_ro->m_type	= RenderObjectType::SkinnedTree;
	}

	void UnRegister()
	{
		//free
	}
};

struct View
{
	float4x4 m_view;
	float4x4 m_projection;
};

struct GraphicWorld
{
	RendererFeatures	m_features;
	VisibibilityWorld	m_visibility_world;
};

struct GameWorld
{
	GraphicWorld		m_gw;

	void Update() { }
};

struct Controller
{
	//Joystick goes here
};

struct VisibibilityResults
{
	std::vector<uint32_t>	   m_masks;
	std::vector<RenderObject*> m_v;
};

VisibibilityResults FilterStatics(const VisibibilityWorld* vo, const View* v, size_t vc)
{
	//Parallel for, avx2 frustum culling
	//Frustum culling,
	//Small objects culling
	//return bit set in a view mask for every view the object is visible in
	return VisibibilityResults();
}

VisibibilityResults FilterUpdatedPerFrame(const VisibibilityWorld* vo, const View* v, size_t vc)
{
	//Parallel for, avx2 frustum culling
	//Frustum culling,
	//Small objects culling
	//return bit set in a view mask for every view the object is visible in

	return VisibibilityResults();
}

Controller PollController()
{
	return Controller();
}

struct FrameRenderNode
{
	RenderObject*	m_ro;
};

struct ViewRenderNode
{
	FrameRenderNode* m_frame;
};

int main()
{
	GameWorld go;
	GraphicWorld* gw		= &go.m_gw;
	VisibibilityWorld* vw	= &gw->m_visibility_world;

	std::vector<View> views[2];
	int32_t			  update_frame_index = 1;
	int32_t			  view_frame_index	 = 0;

	Concurrency::task_group g;

	while (true)
	{
		g.wait();

		//Swap indices
		update_frame_index = 1 - view_frame_index;
		view_frame_index   = 1 - update_frame_index;

		//Render N -1
		g.run([gw, &views, view_frame_index]()
		{
				//Generate commands from the frame packets and view packets

		});

		//Simulation N
		g.run([gw, vw, &go, update_frame_index, &views]()
		{
			Concurrency::task_group g;
			Controller c = PollController();

			View	main;
			View	shadow0;
			View	shadow1;

			views[update_frame_index].push_back(main);
			views[update_frame_index].push_back(shadow0);
			views[update_frame_index].push_back(shadow1);

			VisibibilityResults updated_per_frame;
			VisibibilityResults static_per_frame;

			auto view_count = views[update_frame_index].size();

			struct Stats
			{
				uint32_t			  update_frame_nodes[FeatureRenderCount] = {};
				std::vector<uint32_t> update_view_nodes[FeatureRenderCount]  = {};

				uint32_t			  static_frame_nodes[FeatureRenderCount] = {};
				std::vector<uint32_t> static_view_nodes[FeatureRenderCount] = {};
			};

			Stats s;

			s.update_view_nodes[SkinnedRendererFeatures::Index].resize(view_count);
			s.update_view_nodes[TreeRendererFeatures::Index].resize(view_count);

			s.static_view_nodes[SkinnedRendererFeatures::Index].resize(view_count);
			s.static_view_nodes[TreeRendererFeatures::Index].resize(view_count);

			//Visible object lists
			g.run([&s, &go, vw, &views, update_frame_index, &c, &updated_per_frame]()
			{
				//Handle controller
				go.Update();
				updated_per_frame = FilterUpdatedPerFrame(vw, &views[update_frame_index][0], views[update_frame_index].size());

				for (auto i = 0U; i < updated_per_frame.m_v.size(); ++i)
				{
					RenderObject* o = updated_per_frame.m_v[i];
					uint32_t mask	= updated_per_frame.m_masks[i];

					//Do a scatter op
					for (auto j = 0U; j < FeatureRenderCount; ++j)
					{
						if (o->m_renderer_handle[j] != 0)
						{
							s.update_frame_nodes[j] = s.update_frame_nodes[j] + 1;

							//Iterate over views (up to 32)
							for (auto v = 0U; i < s.update_view_nodes[j].size(); ++v)
							{
								//view is packed in a bit
								if ((1 << v) &  mask)
								{
									s.update_view_nodes[j][v] = s.update_view_nodes[j][v] + 1;
								}
							}
						}
					}
				}
			});

			//Predictive Visibility N
			g.run([&s, vw, &views, update_frame_index, &static_per_frame]()
			{
				static_per_frame = FilterStatics(vw, &views[update_frame_index][0], views[update_frame_index].size());

				for (auto i = 0U; i < static_per_frame.m_v.size(); ++i)
				{
					RenderObject* o = static_per_frame.m_v[i];
					uint32_t mask = static_per_frame.m_masks[i];

					//Do a scatter op
					for (auto j = 0U; j < FeatureRenderCount; ++j)
					{
						if (o->m_renderer_handle[j] != 0)
						{
							s.static_frame_nodes[j] = s.static_frame_nodes[j] + 1;

							//Iterate over views (up to 32)
							for (auto v = 0U; i < s.update_view_nodes[j].size(); ++v)
							{
								//view is packed in a bit
								if ((1 << v) &  mask)
								{
									s.static_view_nodes[j][v] = s.static_view_nodes[j][v] + 1;
								}
							}
						}
					}
				}
			});
			g.wait();

			//Simulate frame packet and allocate based on statistics
			std::vector<uint8_t> frame_packet[FeatureRenderCount];
			frame_packet[SkinnedRendererFeatures::Index].resize(( s.static_frame_nodes[SkinnedRendererFeatures::Index]  + s.update_frame_nodes[SkinnedRendererFeatures::Index] ) * SkinnedRendererFeatures::frame_packet_size());
			frame_packet[TreeRendererFeatures::Index].resize(( s.static_frame_nodes[TreeRendererFeatures::Index] + s.update_frame_nodes[TreeRendererFeatures::Index]) * TreeRendererFeatures::frame_packet_size());

			//views allocate space for the view render nodes
			std::vector< std::vector<uint8_t> > view_frame_packet[FeatureRenderCount];

			//Allocate space for the views
			view_frame_packet[SkinnedRendererFeatures::Index].resize(view_count);
			view_frame_packet[TreeRendererFeatures::Index].resize(view_count);

			//Allocate space for all visible view nodes
			for (auto v = 0U; v < view_count; ++v)
			{
				view_frame_packet[SkinnedRendererFeatures::Index][v].resize( s.static_view_nodes[SkinnedRendererFeatures::Index][v] *  SkinnedRendererFeatures::view_packet_size());
				view_frame_packet[TreeRendererFeatures::Index][v].resize(s.static_view_nodes[TreeRendererFeatures::Index][v] * TreeRendererFeatures::view_packet_size());
			}

			//Populate masks
			size_t skinnedIndex = 0;
			size_t treeIndex	= 0;

			std::vector<uint32_t> viewIndex[FeatureRenderCount];
			viewIndex[SkinnedRendererFeatures::Index].resize(view_count);
			viewIndex[TreeRendererFeatures::Index].resize(view_count);

			//can be done in parallel
			for (auto i = 0U; i < static_per_frame.m_v.size(); ++i)
			{
				constexpr size_t skinnedFrameStride		= SkinnedRendererFeatures::frame_packet_size();
				constexpr size_t treeFrameStride		= TreeRendererFeatures::frame_packet_size();

				constexpr size_t skinnedViewStride		= SkinnedRendererFeatures::view_packet_size();
				constexpr size_t treeViewStride			= TreeRendererFeatures::view_packet_size();

				RenderObject* o						= static_per_frame.m_v[i];
				uint32_t	  m						= static_per_frame.m_masks[i];

				if (o->m_renderer_handle[SkinnedRendererFeatures::Index] != 0)
				{
					uint8_t* position		= &frame_packet[SkinnedRendererFeatures::Index][skinnedFrameStride * skinnedIndex];
					FrameRenderNode* node	= reinterpret_cast<FrameRenderNode*>(position);
					node->m_ro				= o;
					skinnedIndex++;

					for (auto v = 0U; v < view_count; ++v)
					{
						if (((1 << v) & m) != 0)
						{
							uint8_t* position = &view_frame_packet[SkinnedRendererFeatures::Index][v][skinnedViewStride * viewIndex[SkinnedRendererFeatures::Index][v] ];
							ViewRenderNode* n = reinterpret_cast<ViewRenderNode*>(position);

							//Now view render node points to the frame
							n->m_frame = node;
						}
					}
				}

				if (o->m_renderer_handle[TreeRendererFeatures::Index] != 0)
				{
					uint8_t* position = &frame_packet[TreeRendererFeatures::Index][treeFrameStride * treeIndex];
					FrameRenderNode* node = reinterpret_cast<FrameRenderNode*>(position);
					node->m_ro = o;
					treeIndex++;

					for (auto v = 0U; v < view_count; ++v)
					{
						if (((1 << v) & m) != 0)
						{
							uint8_t* position = &view_frame_packet[TreeRendererFeatures::Index][v][treeViewStride * viewIndex[TreeRendererFeatures::Index][v]];
							ViewRenderNode* n = reinterpret_cast<ViewRenderNode*>(position);

							//Now view render node points to the frame
							n->m_frame = node;
						}
					}
				}

				//Now frame_packet per feature contains FrameRenderNodes 
				//Now view packet contains contains VieRenderNodes 
				//And they are prepared for extract per frame, per view

				//Missing stuff to do:
				//Every view will want to have different allocation size, so we need to add the concept of a view type

			}
		});
	}

}

