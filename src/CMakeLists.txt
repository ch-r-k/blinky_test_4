set(SOURCE
    main.cpp
    application_layer/application_manager.cpp
    device_layer/device_manager.cpp
    hardware_layer/hardware_manager.cpp
    hardware_layer/gpio/gpio.cpp
)

target_sources(${PROJECT}_lib PRIVATE ${SOURCE})