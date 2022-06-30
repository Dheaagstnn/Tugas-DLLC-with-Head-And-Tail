//Nama      : Dhea Ayu Agustin
//NIM       : 1121031027
//Kelas     : Informatika A
//Deskripsi : Program Double Linked List Circular dengan head dan  tail, pada program ini
//ditambahkan function untuk mencari data tertentu dan function untuk menghapus data tertentu.
#include <iostream>

using namespace std;
#include <iostream>
using namespace std;

struct TNode {
    int data;       // field data
    TNode *next;    // field pointer next
    TNode *prev;    // field pointer prev
};

TNode *head, *tail; // deklarasi variabel pointer head untuk menunjukkan kepala node

void init() {
    head = NULL;
    tail = NULL;
}

int isEmpty() {
    if (tail == NULL) {
        return 1;
    } else {
        return 0;
    }
}

void insertDepan(int dataBaru) {
    TNode *nodeBaru;
    nodeBaru = new TNode;

    nodeBaru->data = dataBaru;
    nodeBaru->next = nodeBaru;
    nodeBaru->prev = nodeBaru;

    if (isEmpty() == 1) {
        head = nodeBaru;
        tail = nodeBaru;
        head->next = head;
        head->prev = head;
        tail->next = tail;
        tail->prev = tail;
    } else {
        nodeBaru->next = head;
        head->prev = nodeBaru;
        head = nodeBaru;
        head->prev = tail;
        tail->next = head;
    }

    cout << "Data " << dataBaru << " masuk sebagai node paling depan" << endl;
}

void insertBelakang(int dataBaru) {
    TNode *nodeBaru;
    nodeBaru = new TNode;

    nodeBaru->data = dataBaru;
    nodeBaru->next = nodeBaru;
    nodeBaru->prev = nodeBaru;

    if (isEmpty() == 1) {
        head = nodeBaru;
        tail = nodeBaru;
        head->next = head;
        head->prev = head;
        tail->next = head;
        tail->prev = head;
    } else {
        tail->next = nodeBaru;
        nodeBaru->prev = tail;
        tail = nodeBaru;
        tail->next = head;
        head->prev = tail;
    }

    cout << "Data " << dataBaru << " masuk sebagai node paling belakang" << endl;
}

void hapusDepan() {
    TNode *nodeHapus;
    int d;

    if (isEmpty() == 0) {
        if (head != tail) {
            nodeHapus = head;
            d = nodeHapus->data;
            head = head->next;
            tail->next = head;
            head->prev = tail;
            delete nodeHapus;
        } else {
            d = head->data;
            head = NULL;
            tail = NULL;
        }
        cout << "Data " << d << "TERHAPUS" << endl;
    } else {
        cout << "Linked List Masih Kosong\n";
    }
}

void hapusBelakang() {
    TNode *nodeHapus,*nodeBantu;
    int d;

    if (isEmpty() == 0) {
        if (head != head) {
            nodeHapus = tail;
            d = nodeHapus->data;
            tail = tail->prev;
            tail->next = head;
            head->prev = tail;
            delete nodeHapus;
        } else {
            d = head->data;
            head = NULL;
            tail = NULL;
        }
        cout << "Data " << d << "TERHAPUS" << endl;
    } else {
        cout << "Linked List Masih Kosong\n";
    }
}

void hapusData(int hapus)
{
    TNode *nodeBantu, *nodeHapus, *nodeBantu2;
    nodeBantu = head;
    if (isEmpty() == 0){

        while (nodeBantu != NULL){
            if(nodeBantu -> data == hapus){
            nodeHapus = nodeBantu;
            nodeBantu2 = nodeBantu -> prev;
            nodeBantu = nodeBantu -> next;

            delete nodeHapus;
            nodeBantu2 -> next = nodeBantu;
            nodeBantu -> prev = nodeBantu2;
            tail ->next = head;
            head -> prev = tail;
            cout << "Data" << hapus << "Telah Terhapus\n";
            return;

            }else {
                nodeBantu = nodeBantu -> next;
                if(tail -> next == nodeBantu){
                    cout << "Data Tidak Ditemukan" << endl;
                    return;
                }
            }
        }
    }
}

void tampilData() {
    TNode *nodeBantu;

    nodeBantu = head;

    if (isEmpty() == 0) {
        do {
            cout << nodeBantu->data << endl;
            nodeBantu = nodeBantu->next;
        } while (nodeBantu != head);
    } else {
        cout << "Linked List Masih Kosong" << endl;
    }
}
void cariData(int cari){
    TNode *nodeBantu;
    nodeBantu = head;

    if(isEmpty() == 0) {
        while(nodeBantu != NULL) {

          if(nodeBantu->data == cari) {
          cout << "Data Ditemukan-> " << nodeBantu -> data << endl;
            return;
          }else{
            nodeBantu = nodeBantu -> next;
            if (nodeBantu == tail ->next){
            cout << "Data Tidak Ditemukan" << endl;
            return;
            }
          }
        }
        }else {
            cout << "List Kosong" << endl;
            }
}

void hapusSemua() {
    TNode *nodeBantu, *nodeHapus;
    nodeBantu = head;

    while (nodeBantu->next != head) {
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        delete nodeHapus;
    }

    head = NULL;
    cout << "Linked List Kosong\n";
}

int main() {
    int pil, dataBaru;

    do {
        cout<<" \n"<<endl;
        cout<<" ==================================="<<endl;
        cout<<" =     DLLC WITH HEAD AND TAIL     ="<<endl;
        cout<<" ==================================="<<endl;
        cout<<" = 1. Insert Depan                 ="<<endl;
        cout<<" = 2. Insert Belakang              ="<<endl;
        cout<<" = 3. Hapus Depan                  ="<<endl;
        cout<<" = 4. Hapus Belakang               ="<<endl;
        cout<<" = 5. Tampil Data                  ="<<endl;
        cout<<" = 6. Cari Data                    ="<<endl;
        cout<<" = 7. Hapus semua Data             ="<<endl;
        cout<<" = 8. Hapus Data                   ="<<endl;
        cout<<" = 9. Exit                         ="<<endl;
        cout<<" ==================================="<<endl;
        cout<<" Masukan Pilihan : ";
        cin>>pil;

        if (pil == 1) {
            cout<<"Masukan Data = ";
            cin>>dataBaru;
            insertDepan(dataBaru);
        } else if (pil == 2) {
            cout<<"Masukan Data = ";
            cin>>dataBaru;
            insertBelakang(dataBaru);
        } else if (pil == 3) {
            hapusDepan();
        } else if (pil == 4) {
            hapusBelakang();
        } else if (pil == 5) {
            tampilData();
        }else if (pil == 6) {
            cout<< "Masukan Data Yang Dicari :";
            cin>>dataBaru;
            search(dataBaru);
        } else if (pil == 7) {
            hapusSemua();
        }else if (pil == 8) {
            cout<< "Masukan Data Yang Ingin Dihapus :";
            cin>>dataBaru;
            deleteNode(&head, dataBaru);
        } else if (pil != 9) {
            cout<<"\n Maaf, Pilihan Yang Anda Pilih Tidak Tersedia!";
        }
    } while (pil != 9);

    return 0;
}
