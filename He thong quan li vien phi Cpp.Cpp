#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <fstream>
using namespace std;
struct date{
    int ngay;
    int thang;
    int nam;
};
struct benhnhan{
    int maso;
    char ten[50];
    char gioitinh[5];
    date ngaySinh;
    date ngaynhapvien;
    date ngayxuatvien;
    int ngaynamvien;
    int tienthuoc;
    float bhyt;
    int vienphi;
};
typedef benhnhan BN;
void nhapBenhnhan(BN &bn) {
    cout << "\nMa so: ";
    cin >> bn.maso;
    cout << "\nHo Ten: ";
    cin.ignore();  
    cin.getline(bn.ten, sizeof(bn.ten));   
    cout << "\nGioi Tinh: ";
    cin.getline(bn.gioitinh, sizeof(bn.gioitinh));   
    cout << "\nNgay Sinh (dd/mm/yyyy): ";
    cin.ignore();
    cin >> bn.ngaySinh.ngay >> bn.ngaySinh.thang >> bn.ngaySinh.nam;
    cout << "\nNgay nhap vien (dd/mm/yyyy): ";
    cin.ignore();
    cin >> bn.ngaynhapvien.ngay >> bn.ngaynhapvien.thang >> bn.ngaynhapvien.nam;
    cout << "\nNgay xuat vien (dd/mm/yyyy): ";
    cin.ignore();
    cin >> bn.ngayxuatvien.ngay >> bn.ngayxuatvien.thang >> bn.ngayxuatvien.nam;
    cout << "\nBao hiem y te chi tra %: ";
    cin.ignore(); 
    cin >> bn.bhyt;
    cout << "\nTien thuoc: ";
    cin.ignore();
    cin >> bn.tienthuoc;
}
void inDon(BN bn) {
    cout << "\n";
    cout << setw(6) << "Ma so";
    cout << setw(20) << "Ten";
    cout << setw(15) << "Gioi tinh";
    cout << setw(20) << "Ngay sinh";
    cout << setw(20) << "Nhap vien";
    cout << setw(15) << "Ngay benh";
    cout << setw(8) << "BHYT%";
    cout << setw(8) << "Thuoc";
    cout << setw(8) << "Don";
    cout << "\n";
    cout << setw(6) << bn.maso;
    cout << setw(20) << bn.ten;
    cout << setw(15) << bn.gioitinh;
    cout << setw(12) << bn.ngaySinh.ngay << "/" << bn.ngaySinh.thang << "/" << bn.ngaySinh.nam;
    cout << setw(12) << bn.ngaynhapvien.ngay << "/" << bn.ngaynhapvien.thang << "/" << bn.ngaynhapvien.nam;
    cout << setw(15) << bn.ngaynamvien;
    cout << setw(8) << bn.bhyt << "%";
    cout << setw(8) << bn.tienthuoc;
    cout << setw(8) << bn.vienphi;
    
    cout << endl;
}
void tinhsongaynamvien(BN *bn) {
    int dem = 0;

    if (bn->ngayxuatvien.nam == bn->ngaynhapvien.nam) {
        if (((bn->ngaynhapvien.nam % 4 == 0) && (bn->ngaynhapvien.nam % 100 != 0)) || (bn->ngaynhapvien.nam % 400 == 0)) {
            if (bn->ngayxuatvien.thang == bn->ngaynhapvien.thang) {
                dem = bn->ngayxuatvien.ngay - bn->ngaynhapvien.ngay + 1;
            } else {
                if (bn->ngaynhapvien.thang == 1 || bn->ngaynhapvien.thang == 3 || bn->ngaynhapvien.thang == 5 || 
                    bn->ngaynhapvien.thang == 7 || bn->ngaynhapvien.thang == 8 || bn->ngaynhapvien.thang == 10 || 
                    bn->ngaynhapvien.thang == 12) {
                    dem = (31 - bn->ngaynhapvien.ngay) + bn->ngayxuatvien.ngay + 1;
                } else if (bn->ngaynhapvien.thang == 4 || bn->ngaynhapvien.thang == 6 || bn->ngaynhapvien.thang == 9 || 
                           bn->ngaynhapvien.thang == 11) {
                    dem = (30 - bn->ngaynhapvien.ngay) + bn->ngayxuatvien.ngay + 1;
                } else {
                    dem = (29 - bn->ngaynhapvien.ngay) + bn->ngayxuatvien.ngay + 1; 
                }
            }
        } else {
            if (bn->ngayxuatvien.thang == bn->ngaynhapvien.thang) {
                dem = bn->ngayxuatvien.ngay - bn->ngaynhapvien.ngay + 1;
            } else {
                if (bn->ngaynhapvien.thang == 1 || bn->ngaynhapvien.thang == 3 || bn->ngaynhapvien.thang == 5 || 
                    bn->ngaynhapvien.thang == 7 || bn->ngaynhapvien.thang == 8 || bn->ngaynhapvien.thang == 10 || 
                    bn->ngaynhapvien.thang == 12) {
                    dem = (31 - bn->ngaynhapvien.ngay) + bn->ngayxuatvien.ngay + 1;
                } else if (bn->ngaynhapvien.thang == 4 || bn->ngaynhapvien.thang == 6 || bn->ngaynhapvien.thang == 9 || 
                           bn->ngaynhapvien.thang == 11) {
                    dem = (30 - bn->ngaynhapvien.ngay) + bn->ngayxuatvien.ngay + 1;
                } else {
                    dem = (28 - bn->ngaynhapvien.ngay) + bn->ngayxuatvien.ngay + 1; }
            }
        }
    } else {
        dem = 365 * (bn->ngayxuatvien.nam - bn->ngaynhapvien.nam);
    }
    bn->ngaynamvien = dem;
}
void tongvienphi(BN *bn){
    bn->vienphi = (bn->tienthuoc + bn->ngaynamvien*200000)*(1-(bn->bhyt)/100);
}
void themBenhnhan(BN &bn){
    nhapBenhnhan(bn);
    tinhsongaynamvien(&bn);
    tongvienphi(&bn);
    inDon(bn); 
}
void nhapDanhsachbenhnhan(BN ds[], int &n) {
    system("cls");
    do {
        cout << "\nNhap so luong benh nhan: ";
        cin >> n;
    } while (n <= 0); 
    cin.ignore();
    for (int i = 0; i < n; i++) {
        cout << "\nBenh nhan thu " << i + 1 << ":";
        themBenhnhan(ds[i]);
    }
}
void xuatDanhsachbenhnhan(BN ds[], int n) {
    system("cls");
    for (int i = 0; i < n; i++) {
        inDon(ds[i]);  
        cout << "\n";  
    }
}
void Menu(){
    cout << "\n====================HE THONG QUAN LY VIEN PHI====================\n";
    cout << "                      0. Thoat chuong trinh\n";
    cout << "                      1. Nhap danh sach benh nhan\n";
    cout << "                      2. Xuat danh sach benh nhan\n";
    cout << "                      3. Cap nhat hoa don\n";
    cout << "                      4. Xoa benh nhan\n";
    cout << "                      5. Tim kiem hoa don theo ma so\n";
    cout << "                      6. Them mot hoa don\n";
    cout << "                      7. Tinh tong hoa don\n";
    cout << "                      8. Nhap danh sach hoa don tu file\n";
    cout << "                      9. Xuat danh sach hoa don vao file\n";
    cout << "=================================================================\n";
}
void capnhat(BN ds[], int n, int ma) {
    system("cls");
    for (int i = 0; i < n; i++) {
        if (ds[i].maso == ma) {
            nhapBenhnhan(ds[i]);
            tinhsongaynamvien(&ds[i]);
            tongvienphi(&ds[i]);
            inDon(ds[i]);
            break;
        }
    }
}
void xoahoadon(BN ds[], int &n, int ma) {
    system("cls");
    for (int i = 0; i < n; i++) {
        if (ds[i].maso == ma) {
            for (int j = i; j < n - 1; j++) {
                ds[j] = ds[j + 1];
            }
            n--; 
            break;
        }
    }
}
void timkiem(BN ds[], int n, int ma) { 
    system("cls");
    for (int i = 0; i < n; i++) {
        if (ds[i].maso == ma) {  
            inDon(ds[i]);  
            break;  
        }
    }
}
void themmothoadon(BN ds[], int& n) {
    system("cls");
    int i = n; 
    n = n + 1; 
    cout << "\nBenh nhan thu " << i + 1; 
    themBenhnhan(ds[i]); 
}
void tinhtongdon(BN ds[], int n) {
    system("cls");
    int tong = 0; 

    for (int i = 0; i < n; i++) {
        tong += ds[i].vienphi; 
    }

    cout << "\nTong hoa don vien phi: " << tong; 
}
void xuatvaoFile(BN ds[], int n) {
    system("cls");
    string tenFile;
    cout << "\nNhap vao ten file: ";
    getline(cin >> ws, tenFile);
    ofstream f(tenFile, std::ios::binary); 
    if (!f.is_open()) {
        cout << "\nKhong mo duoc file";
        return;
    }

    f.write(reinterpret_cast<char*>(&n), sizeof(n)); 
    for (int i = 0; i < n; ++i) {
        f.write(reinterpret_cast<char*>(&ds[i]), sizeof(ds[i])); 
    }

    f.close();
}
void nhaptuFile(BN ds[], int& n) { 
    system("cls");
    string tenFile;
    cout << "\nNhap vao ten file: ";
    getline(cin >> ws, tenFile);

    ifstream f(tenFile, std::ios::binary); 
    if (!f.is_open()) {
        cout << "\nKhong mo duoc file";
        return;
    }
    f.read(reinterpret_cast<char*>(&n), sizeof(n)); 
    for (int i = 0; i < n; ++i) {
        f.read(reinterpret_cast<char*>(&ds[i]), sizeof(ds[i])); 
    }

    f.close(); 
}
int main(){
   int chon =0;
   struct benhnhan ds[1000];
   int n=0;
   do
   {
    Menu();
    cout << "\nNhap lua chon: ";
    cin >> chon;
    switch (chon)
    {
    case 0:
        {
        printf("\nThoat chuong trinh!\n");
        break;
        }
    case 1:
        {
            nhapDanhsachbenhnhan(ds,n);
            break;
        }
    case 2:
        {
            xuatDanhsachbenhnhan(ds,n);
            break;
        }
    case 3:
        {
            int ma;
            cout << "Nhap vao ma benh nhan can cap nhat: "; cin >> ma;  
            capnhat(ds,n,ma); 
            break;
        }
    case 4:
        {   
            int ma;
            cout << "Nhap vao ma benh nhan can xoa: "; cin >> ma;
            xoahoadon(ds,n,ma);
            n=n-1;
            break;
        }
    case 5:
        {
            int ma;
            cout << "Nhap vao ma benh nhan can tim: "; cin >> ma;
            timkiem(ds,n,ma);
            break;
        }
    case 6:
        {
            themmothoadon(ds,n);
            n=n+1;
            break;
        }
    case 7:
        {
            xuatDanhsachbenhnhan(ds,n);
            tinhtongdon(ds,n);
            break;
        }
    case 8:
        {
            nhaptuFile(ds,n);
            break;
        }
    case 9:
        {
            xuatvaoFile(ds,n);
            break;
        }
    default:
        {
        printf("\nLua chon khong hop le vui long nhap lai lua chon!\n");
            break;
        }
    }
   }while(chon != 0);
}


