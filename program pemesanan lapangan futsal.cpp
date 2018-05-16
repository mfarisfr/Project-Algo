#include<bits/stdc++.h>
using namespace std;

ifstream dtout;
ofstream dtin;

void admin();
void qsort(int first,int last);
void pelanggan();
void menuadmin();
void cari();
void urut();
void boking();
void databoking();

typedef struct
{
    string namalap, jenislap;
    double hargalap, retinglap;
}data;
data lap[1000];
typedef struct
{
    char namapelanggan[20], tanggal[20], namalapangan[20], jslapangan[20];
    int jam;
}bo;
bo king[100];

FILE *a1;
int x, a, jumlap, i, d, pil, hargalap, retinglap, ph, j,wkt, jumbok, pesanan=0;
char y, b, c, e, f, g, h;
string usser, password, namalap, jenislap, nmlap,nmpel,tgl,jnlap;
bool found;

int main()
{
    do{
    cout << setw(30) << setfill('=') << "" << endl;
    cout << setw(18) << setfill(' ') << "LOGIN\n";
    cout << setw(30) << setfill('_') << "" << endl << endl;
    cout << "1. Admin\n2. Pelanggan\n\n";
    cout << setw(30) << setfill('=') << "" << endl;
    cout << "Pilihan(1...2) = "; cin >> x;
    cout << "\n\n";
    switch(x)
    {
        case 1: admin();
        break;
        case 2: pelanggan();
        break;
        default: cout << "Input Salah\n";
    }
    cout << "\nKembali ke menu login? (y/t)\n"; cin >> c;
    cout << endl;
    }while(c=='y' || c=='Y');
}

void admin()
{
    do{
    cout << setw(30) << setfill('*') << "" << endl;
    cout << setw(20) << setfill(' ') << "LOGIN ADMIN\n";
    cout << setw(30) << setfill('_') << "" << endl << endl;
    cout << "Ussername\t: "; cin >> usser;
    cout << "Password\t: "; cin >> password;
    cout << endl;
    if(usser=="admin" && password=="bismillah")
    {
        cout << "Login Berhasil!!\n";
        cout << setw(30) << setfill('*') << "" << endl << endl;
        menuadmin();
    }
    else
    {
        cout << "Ussername atau Password salah!\n";
        cout << "Coba lagi? (y/t)"; cin >> y;
        cout << setw(30) << setfill('*') << "" << endl << endl;
    }
    }while(y=='y' || y=='Y');
}

void pelanggan()
{
    do{
	cout << setw(26) << setfill(' ') << "MENU PELANGGAN : " << endl;
	cout << "1. Daftar lapangan\n2. Cari lapangan\n3. Urut lapangan\n4. Booking\n";
	cout << "Pilihan (1...4) = "; cin >> d;
	switch(d)
	{
		case 1:
		{
			cout << setw(60) << setfill('=') << "" << endl;
            cout << setw(36) << setfill(' ') << "DAFTAR LAPANGAN" << endl;
            cout << setw(60) << setfill('=') << "" << endl;
            cout << "No  Nama\t\tJenis\tHarga\t\tReting\n";
            cout << setw(60) << setfill('-') << "" << endl;
            dtout.open ("lapangan.txt");
            dtout >> jumlap;
            for(i=0; i<jumlap; i++)
            {
            	dtout >> lap[i].namalap;
                dtout >> lap[i].jenislap;
                dtout >> lap[i].hargalap;
                dtout >> lap[i].retinglap;
                cout << i+1 << "  ";
                cout << lap[i].namalap << "\t\t";
                cout << lap[i].jenislap << "\t";
                cout << lap[i].hargalap << "\t\t";
                cout << lap[i].retinglap << endl;
            }
            cout << setw(60) << setfill('=') << "" << endl;
            dtout.close();
        }
        break;
        case 2: cari();
        break;
        case 3: urut();
        break;
        case 4: boking();
        break;
	}
	cout << "Kembali ke menu pelanggan? (y/t) "; cin >> f;
	cout << endl;
	}while(f=='y' || f=='Y');
}

void menuadmin()
{
    do{
    cout << setw(22) << setfill(' ') << "MENU ADMIN : " << endl;
    cout << "1. Input data lapangan\n2. Output data lapangan\n";
    cout << "3. Daftar Boking\n";
    cout << "Pilihan (1...3) = "; cin >> a;
    cout << endl;
    switch(a)
    {
        case 1:
        {
        	dtin.open ("lapangan.txt");
            cout << "\nMasukkan jumlah lapangan : "; cin >> jumlap;
            dtin << jumlap << endl;
            for(i=0; i<jumlap; i++)
            {
                cout << "\nLapangan " << i+1 << endl;
                cout << "Nama Lapangan\t : "; cin.ignore(); getline(cin, lap[i].namalap);
                cout << "Jenis Lapangan\t : "; cin >> lap[i].jenislap;
                cout << "Harga\t\t : "; cin >> lap[i].hargalap;
                cout << "Reting\t\t : "; cin >> lap[i].retinglap;
                dtin << lap[i].namalap << endl;
                dtin << lap[i].jenislap << endl;
                dtin << lap[i].hargalap << endl;
                dtin << lap[i].retinglap << endl;
            }
    		dtin.close();
    	}
        break;
        case 2:
        {
            cout << setw(60) << setfill('=') << "" << endl;
            cout << setw(36) << setfill(' ') << "DAFTAR LAPANGAN" << endl;
            cout << setw(60) << setfill('=') << "" << endl;
            cout << "No  Nama\t\tJenis\tHarga\t\tReting\n";
            cout << setw(60) << setfill('-') << "" << endl;
            dtout.open ("lapangan.txt");
            dtout >> jumlap;
            for(i=0; i<jumlap; i++)
            {
            	dtout >> lap[i].namalap;
                dtout >> lap[i].jenislap;
                dtout >> lap[i].hargalap;
                dtout >> lap[i].retinglap;
                cout << i+1 << "  ";
                cout << lap[i].namalap << "\t\t";
                cout << lap[i].jenislap << "\t";
                cout << lap[i].hargalap << "\t\t";
                cout << lap[i].retinglap << endl;
            }
            cout << setw(60) << setfill('=') << "" << endl;
            dtout.close();
        }
        break;
        case 3:
        {
        databoking();
        }
        break;
        default: cout << "Input Salah\n";
    }
    cout << "\nApakah ingin mengulang? (y/t)\n"; cin >> b;
    cout << endl;
    }while(b=='y' || b=='Y');
}

void cari()
{
	dtout.open("lapangan.txt");
	dtout >> jumlap;
    for(i=0; i<jumlap; i++)
    {
       	dtout >> lap[i].namalap;
        dtout >> lap[i].jenislap;
        dtout >> lap[i].hargalap;
        dtout >> lap[i].retinglap;
	}
	do{
    cout << "\nMenu : ";
    cout << "\nCari Lapangan : \n";
    cout << "1. Nama Lapangan\n2. Jenis Lapnagan\n3. Harga\n4. Reting\n";
    cout << "Masukkan pilihan : "; cin >> pil;
    switch(pil)
    {
        case 1:
        {
    		cout << "Masukkan Nama Lapangan\t: "; cin.ignore(); getline(cin,namalap);
    		found = false;
    		for(i=0; i<jumlap; i++)
    		{
        	if(namalap==lap[i].namalap)
        		{
            		cout << "\nLapangan " << i+1 << endl;
            		cout << "Nama Lapangan\t: " << lap[i].namalap << endl;
            		cout << "Jenis Lapangan\t: " << lap[i].jenislap << endl;
            		cout << "Harga\t\t: " << lap[i].hargalap << endl;
            		cout << "Reting\t\t: " <<  lap[i].retinglap << endl;
            		found=true;
        		}
    		}
    		if (found==false) cout << "Data tidak ada" << endl;
		}
        break;
        case 2:
        {
        	cout << "Masukkan Jenis Lapangan\t: "; cin.ignore(); getline(cin,jenislap);
    		found = false;
    		for(i=0; i<jumlap; i++)
    		{
        		if(jenislap==lap[i].jenislap)
        		{
        			cout << "\nLapangan " << i+1 << endl;
            		cout << "Nama Lapangan\t: " << lap[i].namalap << endl;
            		cout << "Jenis Lapangan\t: " << lap[i].jenislap << endl;
            		cout << "Harga\t\t: " << lap[i].hargalap << endl;
            		cout << "Reting\t\t: " <<  lap[i].retinglap << endl;
            		found=true;
        		}
        	}
        	if (found==false) cout << "Data tidak ada" << endl;
    	}
        break;
        case 3:
        {
        	cout << "Masukkan Harga Lapangan\t: "; cin >> hargalap;
    		found = false;
    		for(i=0; i<jumlap; i++)
    		{
        		if(hargalap==lap[i].hargalap)
        		{
            		cout << "\nLapangan " << i+1 << endl;
            		cout << "Nama Lapangan\t: " << lap[i].namalap << endl;
            		cout << "Jenis Lapangan\t: " << lap[i].jenislap << endl;
            		cout << "Harga\t\t: " << lap[i].hargalap << endl;
            		cout << "Reting\t\t: " <<  lap[i].retinglap << endl;
            		found=true;
            	}
   			 }
   			 if (found==false) cout << "Data tidak ada" << endl;
		}
        break;
        case 4:
        {
        	cout << "Masukkan Reting Lapangan\t: "; cin >> retinglap;
    		found = false;
    		for(i=0; i<jumlap; i++)
    		{
        		if(retinglap==lap[i].retinglap)
        		{
            		cout << "\nLapangan " << i+1 << endl;
            		cout << "Nama Lapangan\t: " << lap[i].namalap << endl;
            		cout << "Jenis Lapangan\t: " << lap[i].jenislap << endl;
            		cout << "Harga\t\t: " << lap[i].hargalap << endl;
            		cout << "Reting\t\t: " <<  lap[i].retinglap << endl;
            		found=true;
            	}
   			 }
   			 if (found==false) cout << "Data tidak ada" << endl;
		}
        break;
        default: cout << "Input Salah\n";
    }
    dtout.close();
    cout << "Apakah Anda ingin mengulang? (y/t)"; cin >> e;
    cout << endl;
    }while(e=='y' || e=='Y');
}

void urut()
{
	dtout.open("lapangan.txt");
	dtout >> jumlap;
    for(i=0; i<jumlap; i++)
    {
       	dtout >> lap[i].namalap;
        dtout >> lap[i].jenislap;
        dtout >> lap[i].hargalap;
        dtout >> lap[i].retinglap;
	}
	do
	{
    cout << "\nMenu : ";
    cout << "\nUrut Lapangan : \n";
	cout << "1. Berdasarkan Harga\n2. Berdasarkan Rating\n";
	cout << "Pilih (1..2) "; cin >> ph; cout << endl;
	switch(ph)
	{
		case 1:
		{
			cout << "Berdasarkan Harga \n";
			cout << "Dari Harga Tertinggi(h) atau Dari Harga Terendah(L)\n";
			cout << "Pilih (H/L) ";cin >> h;
			data temp;
	        if(h=='l'||h=='L')
			{
				for (i=0;i<jumlap;i++)
    			{
        			for (j=i+1;j<jumlap;j++)
        			{
            			if (lap[i].hargalap>lap[j].hargalap)
            			{
  							temp  = lap[i];
                			lap[i]=lap[j];
                			lap[j]= temp;
            			}
        			}
    			}
    			cout << "\tUrutan Harga Dari yang Terendah "<<endl;
    			cout << setw(60) << setfill('=') << "" << endl;
            	cout << setw(36) << setfill(' ') << "DAFTAR LAPANGAN" << endl;
            	cout << setw(60) << setfill('=') << "" << endl;
            	cout << "No  Nama\t\tJenis\tHarga\t\tReting\n";
           		cout << setw(60) << setfill('-') << "" << endl;
    			for (int i=0;i<jumlap;i++)
    			{
     				cout << i+1 << "  ";
                	cout << lap[i].namalap << "\t\t";
                	cout << lap[i].jenislap << "\t";
                	cout << lap[i].hargalap << "\t\t";
                	cout << lap[i].retinglap << endl;
    			}
    			cout << setw(60) << setfill('=') << "" << endl;
    		}
    		if(h=='h'||h=='H')
    		{
    			for (i=0;i<jumlap;i++)
    			{
        			for (j=i+1;j<jumlap;j++)
        			{
            			if (lap[i].hargalap<lap[j].hargalap)
            			{
  							temp  = lap[i];
                			lap[i]=lap[j];
                			lap[j]= temp;
            			}
        			}
    			}
    			cout << "\tUrutan Harga dari yang Tertinggi "<<endl;
    			cout << setw(60) << setfill('=') << "" << endl;
            	cout << setw(36) << setfill(' ') << "DAFTAR LAPANGAN" << endl;
            	cout << setw(60) << setfill('=') << "" << endl;
            	cout << "No  Nama\t\tJenis\tHarga\t\tReting\n";
           		cout << setw(60) << setfill('-') << "" << endl;
    			for (int i=0;i<jumlap;i++)
    			{
     				cout << i+1 << "  ";
                	cout << lap[i].namalap << "\t\t";
                	cout << lap[i].jenislap << "\t";
                	cout << lap[i].hargalap << "\t\t";
                	cout << lap[i].retinglap << endl;
    			}
    			cout << setw(60) << setfill('=') << "" << endl;
			}
    	break;
    	}
    	case 2:
		{
    		cout << "Berdasarkan Rating \n";
			cout << "Dari Rating Tertinggi(h) atau Dari Rating Terendah(L)\n";
			cout << "Pilih (H/L) ";cin >> h;
			data temp;
	        if(h=='l'||h=='L')
			{
                qsort(0,jumlap-1);
    			cout << "\tUrutan Rating Dari yang Terendah "<<endl;
    			cout << setw(60) << setfill('=') << "" << endl;
            	cout << setw(36) << setfill(' ') << "DAFTAR LAPANGAN" << endl;
            	cout << setw(60) << setfill('=') << "" << endl;
            	cout << "No  Nama\t\tJenis\tHarga\t\tReting\n";
           		cout << setw(60) << setfill('-') << "" << endl;
    			for (int i=0;i<jumlap;i++)
    			{
     				cout << i+1 << "  ";
                	cout << lap[i].namalap << "\t\t";
                	cout << lap[i].jenislap << "\t";
                	cout << lap[i].hargalap << "\t\t";
                	cout << lap[i].retinglap << endl;
    			}
    			cout << setw(60) << setfill('=') << "" << endl;
    		}
    		if(h=='h'||h=='H')
    		{
    			for (i=0;i<jumlap;i++)
    			{
        			for (j=i+1;j<jumlap;j++)
        			{
            			if (lap[i].retinglap<lap[j].retinglap)
            			{
  							temp  = lap[i];
                			lap[i]=lap[j];
                			lap[j]= temp;
            			}
        			}
    			}
    			cout << "\tUrutan Rating dari yang Tertinggi "<<endl;
    			cout << setw(60) << setfill('=') << "" << endl;
            	cout << setw(36) << setfill(' ') << "DAFTAR LAPANGAN" << endl;
            	cout << setw(60) << setfill('=') << "" << endl;
            	cout << "No  Nama\t\tJenis\tHarga\t\tReting\n";
           		cout << setw(60) << setfill('-') << "" << endl;
    			for (int i=0;i<jumlap;i++)
    			{
     				cout << i+1 << "  ";
                	cout << lap[i].namalap << "\t\t";
                	cout << lap[i].jenislap << "\t";
                	cout << lap[i].hargalap << "\t\t";
                	cout << lap[i].retinglap << endl;
    			}
    			cout << setw(60) << setfill('=') << "" << endl;
			}
		break;
		}
	}
	cout << "Mau Mengulang Lagi ?(y/t)";cin >> g;
	}while(g=='y'||g=='Y');
	dtout.close();
}

void qsort(int first,int last)
{
	int low,high;
	data temp;
	lap[i].retinglap;
	low=first;
	high=last;
	do
	{
		while(lap[low].retinglap<lap[(first+last)/2].retinglap)low++;
		while(lap[high].retinglap>lap[(first+last)/2].retinglap)high--;
		if (low<=high)
		{
			temp = lap[low];
			lap[low++]= lap[high];
			lap[high--]=temp;
		}
	}while(low<=high);
	if(first<high) qsort(first,high);
	if(low<last) qsort(low,last);
}

void boking()
{
	a1=fopen("Boking.txt","a");
	cout << "MENU BOKING \n";
	cout << "Jumlah Booking : "; cin >> jumbok;
	pesanan += jumbok;
	//fwrite(&pesanan,sizeof(pesanan),1,a1);
	for(i=0; i<jumbok; i++)
    {
        cout << "Booking " << i+1 << endl;
        cout << "Masukkan Nama Anda\t: "; cin.ignore(); cin.getline(king[i].namapelanggan,20);
        cout << "Masukkan Nama Lapangan\t: "; cin.getline(king[i].namalapangan,20);
        cout << "Masukkan Jenis Lapangan\t: "; cin.getline(king[i].jslapangan,20);
        cout << "Masukkan Tanggal\t: ";cin.getline(king[i].tanggal, 20);
        cout << "Masukkan Jam\t\t: ";cin>>king[i].jam;
        fwrite(&king[i],sizeof(king[i]),1,a1);
    }
    fclose(a1);
}

void databoking()
{
    a1=fopen("Boking.txt","r");
	cout << "DATA BOKING \n";
	//fread(&pesanan,sizeof(pesanan),1,a1);
        i=0;
        while(feof(a1)==NULL)
        {
            fread(&king[i],sizeof(king[i]),1,a1);
            i++;
        }
        cout << setw(70) << setfill('=') << "" << endl;
        cout << setw(40) << setfill(' ') << "DATA BOOKING" << endl;
        cout << setw(70) << setfill('-') << "" << endl;
        cout << "No  Nama Pemesan\tLapangan\tJenis\tTanggal\tJam\n";
        cout << setw(70) << setfill('-') << "" << endl;
        for(j=0; j<i-1; j++)
        {
            cout << j+1 << "   ";
            cout << king[j].namapelanggan << "\t\t";
            cout << king[j].namalapangan << "\t";
            cout << king[j].jslapangan << "\t\t";
            cout << king[j].tanggal << "\t";
            cout << king[j].jam << "\t\n";
        }
        cout << endl;
        cout << setw(70) << setfill('=') << "" << endl;
    fclose(a1);
}
