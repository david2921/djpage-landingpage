#include <iostream>
using namespace std;

// lop doi tuong Person
class Person {
	// cac bien
	private:
		string hoTen; // ho va ten
		string ngaySinh; // ngay sinh
		string queQuan; // que quan
		int soThuTu; // so thu tu
	// cac ham
	public:
		// ham khoi tao mac dinh
		Person() {
			hoTen = "";
			ngaySinh = "";
			queQuan = "";
			soThuTu = 0;
		}
		// ham khoi tao co day du doi so
		Person(string hoTen, string ngaySinh, string queQuan, int soThuTu) {
			this->hoTen = hoTen;
			this->ngaySinh = ngaySinh;
			this->queQuan = queQuan;
			this->soThuTu = soThuTu;
		}
		// ham khoi tao dung de tao ra 1 person thuong
		Person(string hoTen, string ngaySinh, string queQuan) {
			this->hoTen = hoTen;
			this->ngaySinh = ngaySinh;
			this->queQuan = queQuan;
			this->soThuTu = 0;
		}
		// cac ham get
		string getHoTen() {
			return (hoTen);
		}
		string getNgaySinh() {
			return (ngaySinh);
		}
		string getQueQuan() {
			return (queQuan);
		}
		int getSoThuTu() {
			return (soThuTu);
		}
		// cac ham set
		void setHoTen(string hoTen) {
			this->hoTen = hoTen;
		}
		void setNgaySinh(string ngaySinh) {
			this->ngaySinh = ngaySinh;
		}
		void setQueQuan(string queQuan) {
			this->queQuan = queQuan;
		}
		void setSoThuTu(int soThuTu) {
			this->soThuTu = soThuTu;
		}
};

// lop doi tuong Student
class Student : public Person {
	// cac bien cua student
	private:
		int diem; // diem
		string lopHoc; // lop hoc
		Student *next; // Student tiep theo trong danh sach
	// cac phuong thuc cua student
	public :
		// phuong thuc khoi tao cho phep nhap thong tin cua sinh vien
		Student() {
			// khoi tao person
			cout << "Nhap vao ho ten: ";
			string hoTen;
			getline(cin, hoTen);
			cout << "Nhap vao ngay sinh: ";
			string ngaySinh;
			getline(cin, ngaySinh);
			cout << "Nhap vao que quan: ";
			string queQuan;
			getline(cin, queQuan);
			this->setHoTen(hoTen);
			this->setNgaySinh(ngaySinh);
			this->setQueQuan(queQuan);
			// thong tin student
			cout << "Nhap vao diem: ";
			int diem;
			cin >> diem;
			cout << "Nhap vao lop hoc: ";
			string lopHoc;
			cin.ignore();
			getline(cin, lopHoc);
			this->diem = diem;
			this->lopHoc = lopHoc;
			this->next = NULL;
		}
        // khoi tao sinh vien de test
    Student(string hoTen, string ngaySinh, string queQuan, int diem, string lopHoc) {
        this->setHoTen(hoTen);
        this->setNgaySinh(ngaySinh);
        this->setQueQuan(queQuan);
        this->diem = diem;
        this->lopHoc = lopHoc;
        this->next = NULL;
    }
		// cac phuong thuc get
		int getDiem() {
			return (diem);
		}
		string getLopHoc() {
			return (lopHoc);
		}
		Student* getNext() {
			return (next);
		}
		// cac phuong thuc set
		void setDiem(int diem) {
			this->diem = diem;
		}
		void setLopHoc(string lopHoc) {
			this->lopHoc = lopHoc;
		}
		void setNext(Student *next) {
			this->next = next;
		}
		// phuong thuc hien thi toan bo thong tin student
		void hienThiThongTin() {
			cout << "-----------" << endl;
			cout << "So Thu Tu: " << this->getSoThuTu() << endl;
			cout << "Ho Ten: " << this->getHoTen() << endl;
			cout << "Ngay Sinh: " << this->getNgaySinh() << endl;
			cout << "Que Quan: " << this->getQueQuan() << endl;
			cout << "Diem: " << this->getDiem() << endl;
			cout << "Lop Hoc: " << this->getLopHoc() << endl;
		}
};

// cac phuong thuc
// tim kiem sinh vien theo so thu tu
// Input: danh sach sinh vien, so thu tu tim kiem
// Output: Sinh vien phia truoc cua sinh vien can tim, null neu khong tim thay hoac la sinh vien dau tien trong danh sach
Student* timKiemSinhVien(Student *danhSach, int soThuTu) {
	Student *ptr = danhSach;
	while (ptr->getNext() != NULL) {
		Student *next = ptr->getNext();
		if (next->getSoThuTu() == soThuTu) {
			return (ptr);
		}
		ptr = next;
	}
	return (NULL); // khong tim thay hoac la sinh vien dau tien trong danh sach
}

// them 1 sinh vien voi danh sach
// Input: danh sach sinh vien
void themSinhVien(Student *danhSach) {
	// tao sinh vien moi
	Student *svNew = new Student();
	// them vao cuoi danh sach
	Student *ptr = danhSach;
	while (ptr->getNext() != NULL) {
		ptr = ptr->getNext();
	}
	// them so thu tu cho sinh vien moi
	svNew->setSoThuTu(ptr->getSoThuTu() + 1);
	// gan vao cuoi danh sach
	ptr->setNext(svNew);
}

// xoa 1 sinh vien theo so thu tu
// Input: danh sach sinh vien, so thu tu xoa
// Output: true - xoa thanh cong, fasle - xoa that bai
bool xoaSinhVien(Student *danhSach, int soThuTu) {
	// tim kiem vi tri sinh vien
	Student *sinhVienTruocSinhVienCanXoa = timKiemSinhVien(danhSach, soThuTu);
	if (sinhVienTruocSinhVienCanXoa == NULL) {
		// sinh vien can xoa la sinh vien dau danh sach
		if (danhSach->getSoThuTu() == soThuTu && danhSach->getNext() == NULL) {
			danhSach = NULL;
		}
		cout << "Khong tim thay sinh vien can xoa" << endl;
		return (false);
	} else {
		Student *sinhVienCanXoa = sinhVienTruocSinhVienCanXoa->getNext();
		// sinh vien can xoa la sinh vien cuoi cung trong danh sach
		if (sinhVienCanXoa->getNext() == NULL) {
			sinhVienTruocSinhVienCanXoa->setNext(NULL);
			return (true); // xoa thanh cong
		} else {
			// sinh vien nam ben trong danh sach
			sinhVienTruocSinhVienCanXoa->setNext(sinhVienCanXoa->getNext());
			return (true); // xoa thanh cong
		}
	}
}

// sap xep tang dan theo diem trong danh sach sinh vien
// Input: Danh sach sinh vien
void sapXepDanhSach(Student *danhSach) {
	// duyet het danh sach
	Student *ptr = danhSach;
	while (ptr != NULL) {
		if (ptr->getDiem() > ptr->getNext()->getDiem()) {
            cout << "1---" << endl;
			// doi cho vi tri
			Student *temp = ptr->getNext();
			ptr->setNext(ptr);
			ptr = temp;
			// doi vi tri next cua 2 phan tu
//            ptr->setNext(ptr);
//            ptr->getNext()->setNext(temp->getNext());
        }  else {
            ptr = ptr->getNext();
        }
	}
//    while (ptr->getNext() != NULL) {
//        Student *next = ptr->getNext();
//        while (next != NULL) {
//            
//            if (ptr->getDiem() > next->getDiem()) {
//                // doi vi tri
//                Student *temp = next;
//                next = ptr;
//                ptr = temp;
//                cout << "1" << endl;
//            }
//            next = next->getNext();
//        }
//        ptr = ptr->getNext();
//    }
    Student *ptrT = ptr;
    while (ptrT != NULL) {
        ptrT->hienThiThongTin();
        ptrT = ptrT->getNext();
    }
}

int main() {
	
	Student *st1 = new Student("h1", "1", "q1", 4, "d1");
	Student *st2 = new Student("h2", "2", "q2", 1, "d2");
    Student *st3 = new Student("h3", "3", "q3", 5, "d3");
	st1->setNext(st2);
    st2->setNext(st3);
	
	Student *ptr = st1;
	while (ptr != NULL) {
		ptr->hienThiThongTin();
		ptr = ptr->getNext();
	}
    
//    xoaSinhVien();
    sapXepDanhSach(st1);
    
    cout << "------------------------------" << endl;
//    ptr = st1;
//    while (ptr != NULL) {
//        ptr->hienThiThongTin();
//        ptr = ptr->getNext();
//    }
    
	return (0);
}

