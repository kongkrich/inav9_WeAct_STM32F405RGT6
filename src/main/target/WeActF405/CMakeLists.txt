cmake_minimum_required(VERSION 3.13)

# Target name must match folder name: WeActF405
# MCU: STM32F405RGT6 (1MB Flash, 192KB RAM, 168MHz)
# HSE: WeAct board uses 8MHz external crystal (default for F405)

target_stm32f405xg(WeActF405)
