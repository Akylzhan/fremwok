target_sources(${PROJECT_NAME} PRIVATE
	main.cpp
	AppState.h AppState.cpp
	Drawable.h
	Triangle.h Triangle.cpp
	Texture.h Texture.cpp
	TexturedQuadShader.h TexturedQuadShader.cpp
)

target_include_directories(${PROJECT_NAME} PRIVATE .)