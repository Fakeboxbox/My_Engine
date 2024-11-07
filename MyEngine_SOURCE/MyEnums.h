#pragma once

namespace my::enums
{
	enum class eComponentType
	{
		Transform,
		SpriteRenderer,
		Animator,
		Script,
		Camera,
		End
	};

	enum class eLayerType
	{
		None,
		BackGround,
		Player,
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
