
project(discord_game_sdk)

set(DISCORD_PREFIX "/home/roman/proj/yuzu/mr/discord/yuzu/externals/discord_game_sdk")
set(DISCORD_INCLUDE_DIR "${DISCORD_PREFIX}/cpp")
set(DISCORD_LIBRARY_DIR "${DISCORD_PREFIX}/lib/x86_64")
if (UNIX) 
    set(DISCORD_LIBRARY "${DISCORD_LIBRARY_DIR}/libdiscord_game_sdk.so")
endif (UNIX)
if (WIN32)
    set(DISCORD_LIBRARY "${DISCORD_LIBRARY_DIR}/libdiscord_game_sdk.dll")
endif (WIN32)

#$link_directories("${DISCORD_PREFIX}/lib/x86_64/")
add_library(discord_game_sdk_st STATIC
    ./cpp/achievement_manager.cpp
    ./cpp/achievement_manager.h
    ./cpp/activity_manager.cpp
    ./cpp/activity_manager.h
    ./cpp/application_manager.cpp
    ./cpp/application_manager.h
    ./cpp/core.cpp
    ./cpp/core.h
    ./cpp/discord.h
    ./cpp/event.h
    ./cpp/ffi.h
    ./cpp/image_manager.cpp
    ./cpp/image_manager.h
    ./cpp/lobby_manager.cpp
    ./cpp/lobby_manager.h
    ./cpp/network_manager.cpp
    ./cpp/network_manager.h
    ./cpp/overlay_manager.cpp
    ./cpp/overlay_manager.h
    ./cpp/relationship_manager.cpp
    ./cpp/relationship_manager.h
    ./cpp/storage_manager.cpp
    ./cpp/storage_manager.h
    ./cpp/store_manager.cpp
    ./cpp/store_manager.h
    ./cpp/types.cpp
    ./cpp/types.h
    ./cpp/user_manager.cpp
    ./cpp/user_manager.h
    ./cpp/voice_manager.cpp
    ./cpp/voice_manager.h
)
add_library(discord_game_sdk INTERFACE) 
#target_include_directories(discord_game_sdk INTERFACE "${DISCORD_INCLUDE_DIR}")
target_link_libraries(discord_game_sdk INTERFACE "${DISCORD_LIBRARY}")
target_link_libraries(discord_game_sdk_st discord_game_sdk)

#add_subdirectory(discord-rpc EXCLUDE_FROM_ALL)
#target_include_directories(discord-rpc INTERFACE ./discord-rpc/include)
#add_subdirectory(discord_game_sdk EXCLUDE_FROM_ALL)
#target_include_directories(discord_game_sdk INTERFACE ./cpp)
#
##add_library(discord_game_sdk SHARED IMPORTED)
##set_property(TARGET discord_game_sdk PROPERTY IMPORT_LOCATION "/home/roman/proj/yuzu/mr/discord/yuzu/externals/discord_game_sdk/lib/x86_64/discord_game_sdk.so")
#
##target_include_directories(discord_game_sdk INTERFACE ./cpp)
##target_include_directories(discord_game_sdk INTERFACE ./discord_game_sdk/lib/x86_64/)
##find_library(discord_game_sdk ./lib/x86_64/)
##link_directories(discord_game_sdk ./lib/x86_64/)
##target_link_libraries(discord_game_sdk discord_game_sdk)
#target_link_libraries(discord_game_sdk "/home/roman/proj/yuzu/mr/discord/yuzu/externals/discord_game_sdk/lib/x86_64/discord_game_sdk.so")
#target_link_libraries(discord_game_sdk discord_game_sdk /home/roman/proj/yuzu/mr/discord/yuzu/externals/discord_game_sdk/lib/x86_64/discord_game_sdk.so)
    #target_link_libraries(discord_game_sdk discord_game_sdk)
