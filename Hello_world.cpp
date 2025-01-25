
// #include "hello.pio.h"

#define SOT 0x01
#define EOT 0x04
#define ACK 0x06
#define FLAG_VALUE 123

#define HELLO_PIO_LED_PIN PICO_DEFAULT_LED_PIN

void secondary(); // Core 1 entry

int main() // Core 0 entry
{

    stdio_init_all();
    multicore_launch_core1(secondary);

    PIO pio;
    uint sm;
    uint offset;
    uint freq = 9600;

    // bool success = pio_claim_free_sm_and_add_program_for_gpio_range(&hello_program, &pio, &sm, &offset, HELLO_PIO_LED_PIN, 1, true);
    // hard_assert(success);

    // hello_program_init(pio, sm, offset, HELLO_PIO_LED_PIN, freq);

    gpio_set_function(0, GPIO_FUNC_UART);
    gpio_set_function(1, GPIO_FUNC_UART);
    gpio_set_function(4, GPIO_FUNC_UART);
    gpio_set_function(5, GPIO_FUNC_UART);

    uart_init(uart0, 115200);
    uart_init(uart1, 115200);

    uint8_t send_buffer [10];
    uint8_t receive_buffer [10];
    uint8_t counter = 0;

    while (true) {
        printf("Sending from UART0\n");

        send_buffer[0] = counter;
        send_buffer[2] = EOT;

        uart_putc(uart0, send_buffer[0]);
        uart_putc(uart0, send_buffer[1]);
        uart_putc(uart0, send_buffer[2]);

        uint i = 0;
        while(uart_is_readable(uart1)) {

            uart_read_blocking(uart1, (uint8_t *)&receive_buffer[i], 1);
            i++;
        }

        
        printf("Received on UART1: %i, %i, %i\n", receive_buffer[0], receive_buffer[1], receive_buffer[2]);

        sleep_ms(500);

        uint32_t g = multicore_fifo_pop_blocking();

        if(g != FLAG_VALUE)
        {
            printf("Hmm, that's not right on core 0!\n");
        }
        else
        {
            multicore_fifo_push_blocking(FLAG_VALUE);
            printf("Its all gone right on core 0!\n");
        }

        pio_sm_put_blocking(pio, sm, 1);
        sleep_ms(500);
        pio_sm_put_blocking(pio, sm, 0);
        sleep_ms(500);

        counter++;
    }

    // pio_remove_program_and_unclaim_sm(&hello_program, pio, sm, offset);

    return 0;
}

void secondary()
{
    while(true){

        multicore_fifo_push_blocking(FLAG_VALUE);

        uint32_t g = multicore_fifo_pop_blocking();

        if (g != FLAG_VALUE)
        {
            printf("Hmm, that's not right on core 1!\n");
        }
        else
        {
            printf("Its all gone right on core 1!\n");
        }   

        sleep_ms(500);
    }
    // while(true){
    //     tight_loop_contents();
    // }
};

