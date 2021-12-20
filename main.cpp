//Made by MinDl
//
//19.12.2021
//
#include <iostream>
#include <fstream>
#include <thread>
#include <mutex>

using namespace std;
mutex g_lock;

void threads1(string &passbrut1, string userpass) {
	string passbrut;
	char sumbs[62] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z', 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z', '0','1','2','3','4','5','6','7','8','9' };
	for (int a = 0; a < 62; a++) {
		g_lock.lock();
		passbrut = "0";
		passbrut[0] = sumbs[a];
		if (passbrut == userpass) {
			passbrut1 = passbrut;
			cout << "Pass: " << passbrut << endl;
			g_lock.unlock();
			return;
		}
		if (passbrut1 != ".") {
			g_lock.unlock();
			return;
		}
		g_lock.unlock();
		for (int b = 0; b < 62; b++) {
			g_lock.lock();
			passbrut = "00";
			passbrut[0] = sumbs[a];
			passbrut[1] = sumbs[b];
			if (passbrut == userpass) {
				passbrut1 = passbrut;
				cout << "Pass: " << passbrut << endl;
				g_lock.unlock();
				return;
			}
			if (passbrut1 != ".") {
				g_lock.unlock();
				return;
			}
			g_lock.unlock();
			for (int c = 0; c < 62; c++) {
				g_lock.lock();
				passbrut = "000";
				passbrut[0] = sumbs[a];
				passbrut[1] = sumbs[b];
				passbrut[2] = sumbs[c];
				if (passbrut == userpass) {
					passbrut1 = passbrut;
					cout << "Pass: " << passbrut << endl;
					g_lock.unlock();
					return;
				}
				if (passbrut1 != ".") {
					g_lock.unlock();
					return;
				}
				g_lock.unlock();
				for (int d = 0; d < 62; d++) {
					g_lock.lock();
					passbrut = "0000";
					passbrut[0] = sumbs[a];
					passbrut[1] = sumbs[b];
					passbrut[2] = sumbs[c];
					passbrut[3] = sumbs[d];
					if (passbrut == userpass) {
						passbrut1 = passbrut;
						cout << "Pass: " << passbrut << endl;
						g_lock.unlock();
						return;
					}
					if (passbrut1 != ".") {
						g_lock.unlock();
						return;
					}
					g_lock.unlock();
				}
			}
		}
	}
	cout << "Sorry no bruted password1\n";
}

void threads2(string &passbrut2, string userpass) {
	string passbrut;
	char sumbs[62] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z', 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z', '0','1','2','3','4','5','6','7','8','9' };
	for (int a = 61; a >= 0; a--) {
		g_lock.lock();
		passbrut = "0";
		passbrut[0] = sumbs[a];
		if (passbrut == userpass) {
			passbrut2 = passbrut;
			cout << "Pass: " << passbrut << endl;
			g_lock.unlock();
			return;
		}
		if (passbrut1 != ".") {
			g_lock.unlock();
			return;
		}
		g_lock.unlock();
		for (int b = 61; b >= 0; b--) {
			g_lock.lock();
			passbrut = "00";
			passbrut[0] = sumbs[a];
			passbrut[1] = sumbs[b];
			if (passbrut == userpass) {
				passbrut2 = passbrut;
				cout << "Pass: " << passbrut << endl;
				g_lock.unlock();
				return;
			}
			if (passbrut1 != ".") {
				g_lock.unlock();
				return;
			}
			g_lock.unlock();
			for (int c = 61; c >= 0; c--) {
				g_lock.lock();
				passbrut = "000";
				passbrut[0] = sumbs[a];
				passbrut[1] = sumbs[b];
				passbrut[2] = sumbs[c];
				if (passbrut == userpass) {
					passbrut2 = passbrut;
					cout << "Pass: " << passbrut << endl;
					g_lock.unlock();
					return;
				}
				if (passbrut1 != ".") {
					g_lock.unlock();
					return;
				}
				g_lock.unlock();
				for (int d = 61; d >= 0; d--) {
					g_lock.lock();
					passbrut = "0000";
					passbrut[0] = sumbs[a];
					passbrut[1] = sumbs[b];
					passbrut[2] = sumbs[c];
					passbrut[3] = sumbs[d];
					if (passbrut == userpass) {
						passbrut2 = passbrut;
						cout << "Pass: " << passbrut << endl;
						g_lock.unlock();
						return;
					}
					if (passbrut2 != ".") {
						g_lock.unlock();
						return;
					}
					g_lock.unlock();
				}
			}
		}
	}
	cout << "Sorry no bruted password2\n";
}

int main(){
	string userpass;
	string passwd;
	string passbrut = ".";
	cout << "Password: ";
	cin >> userpass;
	string exit;

	while (1) {
		cout << "0)Exit; 1)File; 2)Brut;\n::";
		cin >> exit;
		if (exit == "1" || exit == "1)" || exit == "File" || exit == "file" || exit == "1)exit" || exit == "1)Exit") {
			string filename;
			cout << "Enter Filename: ";
			cin >> filename;
			ifstream file(filename);
			if (!file.is_open()) {
				cout << "Error file can't open";
				system("pause>nul");
				return 0;
			}
			cout << "Processing...\n";
			for (; file >> passwd;) {
				if (passwd == userpass) {
					cout << "Password: " << passwd << endl;
					break;
				}
			}
			break;
		}
		else if (exit == "2" || exit == "2)" || exit == "Brut" || exit == "brut" || exit == "2)brut" || exit == "2)Brut") {
			thread thr1(threads1, ref(passbrut), userpass);
			thread thr2(threads2, ref(passbrut), userpass);
			thr1.join();
			thr2.join();
			break;
		}
		else if (exit == "0" || exit == "0)" || exit == "Exit" || exit == "exit" || exit == "0)exit" || exit == "0)Exit") {
			break;
		}
		else {
			cout << "Wrong command\n";
		}
	}
	cout << "Exiting...";
	system("pause>nul");
	return 0;
}
