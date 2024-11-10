#pragma once

namespace my::enums
{
	enum class eComponentType
	{
		Transform,
		Collider,
		Script,
		SpriteRenderer,
		Animator,
		Camera,
		End
	};

	enum class eLayerType
	{
		None,
		BackGround,
		Player,
		Animal,
		particle,
		// etc...
		Max = 16
	};

	enum class eResourceType
	{
		Texture,
		AudioClip,
		Animation,
		Prefab,
		End
	};
}
