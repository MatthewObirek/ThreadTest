add_library( Object
		"Object/Object.h" 	"Object/Object.cpp"
		"Object/Person.h" 	"Object/Person.cpp"
		"Object/Store.h"  	"Object/Store.cpp"
		"Object/Item.h"   	"Object/Item.cpp"
		"Object/Map.h"		"Object/Map.cpp"
		)

add_library( Debug 
		"Debug/Debug.h"	"Debug/Debug.cpp")

Target_include_directories (Object PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Object)
Target_include_directories (Object PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Debug)
