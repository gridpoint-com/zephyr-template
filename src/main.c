#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>

LOG_MODULE_REGISTER(main);

int main(void)
{
    LOG_INF("Hello world from %s", CONFIG_BOARD_TARGET);
    return 0;
}
