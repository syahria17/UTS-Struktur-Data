#include <iostream>
using namespace std;

struct FoodItem
{
    string name;
    int jumlah;
    double price;
    FoodItem *next;
};
FoodItem *head;

struct MenuItem
{
    string namaMakanan;
    int harga;
} menu[3];

// membuat daftar menu
void declareMenu()
{
    menu[0].namaMakanan = "Nasi Goreng";
    menu[0].harga = 25000;
    menu[1].namaMakanan = "Sosis Bakar";
    menu[1].harga = 10000;
    menu[2].namaMakanan = "Bakso Sapi";
    menu[2].harga = 20000;
}

// list menu
void menuList()
{
    declareMenu();
    cout << "\n\n";
    cout << "No. \tNama Makanan\t\tHarga\n";
    cout << "-------------------------------------\n";

    for (int i = 0; i < size(menu); i++)
    {
        cout << i + 1 << ". \t" << menu[i].namaMakanan << "\t\t" << menu[i].harga << endl;
    }
}

// menampilkan daftar menu
void displayMenu()
{
    char input;
    while (!(input == 'y' || input == 'Y'))
    {
        menuList();
        cout << "\nKembali? (y) : ";
        cin >> input;
    }
}

// Menghitung total harga
double calculateTotalPrice()
{
    double totalPrice = 0;
    FoodItem *current = head;
    while (current != NULL)
    {
        totalPrice += current->price * current->jumlah;
        current = current->next;
    }
    return totalPrice;
}

// menampilkan daftar pesanan
void displayOrder()
{
    double totalPrice = 0;
    char input;
    FoodItem *current = head;
    while (!(input == 'y' || input == 'Y'))
    {
        if (current == NULL)
        {
            cout << "\nAnda belum memesan apapun\n\n";
        }
        else
        {
            int i = 1;
            cout << "\n\nDaftar Pesanan\n";
            cout << "No. \tNama Makanan\t\tHarga\t\tSatuan\t\tJumlah\n";
            cout << "-----------------------------------------------\n";
            while (current != NULL)
            {
                cout << i << "\t" << current->name << "\t\t" << current->price << "\t\t";
                cout << current->jumlah << "\t\t" << current->price * current->jumlah << "\n\n";
                current = current->next;
            }
            cout << "-----------------------------------------------\n";

            cout << "Total harga : " << calculateTotalPrice();
        }
        cout << "\n\nKembali? (y) : ";
        cin >> input;
    }
}

// mencari posisi terakhir linked list
FoodItem *findOrder()
{
    FoodItem *current = head;
    if (current != NULL)
    {
        do
        {
            current = current->next;
        } while (current != NULL);
        return current;
    }
    return NULL;
}

// function untuk menambahkan pesanan
void placeOrder()
{
    int orderNum;
    char choose = 'y';
    FoodItem *current = findOrder();
    while (choose == 'Y' || choose == 'y')
    {
        menuList();
        FoodItem *temp = new FoodItem();
        cout << "\nPilihlah makanan (1/2/3) : ";
        cin >> orderNum;
        temp->name = menu[orderNum - 1].namaMakanan;
        temp->price = menu[orderNum - 1].harga;
        cout << "Masukan Jumlah Makanan : ";
        cin >> temp->jumlah;
        temp->next = NULL;
        if (head == NULL)
        {
            head = temp;
        }
        else
        {
            head->next = temp;
            current = head->next;
        }
        cout << "Tambah Pesanan (y/n)? : ";
        cin >> choose;
    }
}

int main()
{
    int choice;
    cout << "\n\n";
    cout << "\t\t\t    Selamat Datang di Rumah Makan Makmur\n";
    cout << "\t\t\tJalan. Sudirman, No. 12A, Bekasi, Jawa Barat\n";
    cout << "\t\t\t\tWhatsapp: 0812-1212-1212\n";
    cout << "\t\t\t      Gofood >>> Rumah Makan Makmur\n\n";
    cout << "\t\t==============================================================\n\n";
    while (true)
    {
        cout << "Pilih salah satu dari pilihan berikut:\n";
        cout << "1. Lihat Menu Makanan\n";
        cout << "2. Pesan Makanan\n";
        cout << "3. Lihat Daftar Pesanan\n";
        cout << "4. Keluar\nPilihan (1/2/3/4/5) : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            displayMenu();
            break;
        case 2:
            placeOrder();
            break;
        case 3:
            displayOrder();
            break;
        case 4:
            cout << "Program berhenti";
            return 0;
        default:
            cout << "Pilihan tidak tersedia, Silahkan pilih yang tersedia";
        }
    }
    return 0;
}