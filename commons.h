typedef struct {
    int id;
    char name[50];
} Item;

// Struct para Inventario.dat
typedef struct {
    char fecha[9]; //fecha en formato AAAAMMDD (8 caracteres + '\0')
    int entrantes; // Cantidad de artículos entrantes
    int salientes; // Cantidad de artículos salientes
} Movimiento;


// Struct para Pedidos.dat
typedef struct {
    char fecha[9]; //fecha en formato AAAAMMDD (8 caracteres + '\0')
    int codigoCliente; // Código del cliente
    float importePedido; // Importe del pedido en pesos
} Pedido;