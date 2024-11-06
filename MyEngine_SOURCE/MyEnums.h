#pragma once

namespace my::enums
{
	enum class eLayerType
	{
		None,
		BackGround,
		Player,
		// etc...
		Max = 16
	};

	enum class eResourceType
	{
		Texture,
		AudioClip,
		Prefab,
		End
	};
}
