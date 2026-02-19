set(SOURCE
    main.cpp
    hardware_layer/hardware_manager.cpp
    hardware_layer/gpio/gpio.cpp    
)

target_sources(${PROJECT}_lib PRIVATE ${SOURCE})