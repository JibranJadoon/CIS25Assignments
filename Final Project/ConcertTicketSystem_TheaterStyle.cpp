#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

// Constants for seat grid dimensions
const int ROWS = 5;
const int SEATS_PER_ROW = 10;
const int TOTAL_SEATS = ROWS * SEATS_PER_ROW;

// Class representing the concert ticket reservation system
class ConcertTicketSystem {
private:
    // 2D array to track seat booking status (true = booked, false = available)
    bool seats[ROWS][SEATS_PER_ROW];

public:
    // Constructor initializes all seats as available
    ConcertTicketSystem() {
        for (int i = 0; i < ROWS; ++i)
            for (int j = 0; j < SEATS_PER_ROW; ++j)
                seats[i][j] = false;
    }

    // Loads seat data from file to restore previous session bookings
    void loadSeatsFromFile(const string& filename) {
        ifstream file(filename);
        if (file.is_open()) {
            for (int i = 0; i < ROWS; ++i)
                for (int j = 0; j < SEATS_PER_ROW; ++j)
                    file >> seats[i][j];
            file.close();
        }
    }

    // Saves current seat data to file to persist session data
    void saveSeatsToFile(const string& filename) {
        ofstream file(filename);
        for (int i = 0; i < ROWS; ++i)
            for (int j = 0; j < SEATS_PER_ROW; ++j)
                file << seats[i][j] << " ";
        file.close();
    }

    // (O) = available, (X) = booked
    void displaySeatLayout() {
        char rowLabel = 'A';
        cout << "\n        ====== CONCERT SEATING ======\n\n";
        for (int i = 0; i < ROWS; ++i) {
            cout << "Row " << static_cast<char>(rowLabel + i) << "   ";
            for (int j = 0; j < SEATS_PER_ROW; ++j) {
                if (seats[i][j]) {
                    cout << "(X) ";
                } else {
                    cout << "(O) ";
                }
            }
            cout << "\n";
        }
        cout << "\nLegend: (O) = Available, (X) = Booked\n";
    }

    void bookSeat(int row, int seat) {
        if (row < 0 || row >= ROWS || seat < 0 || seat >= SEATS_PER_ROW) {
            cout << "Invalid seat location.\n";
            return;
        }
        if (seats[row][seat]) {
            cout << "Seat already booked.\n";
        } else {
            seats[row][seat] = true;
            cout << "Seat successfully booked.\n";
        }
    }

    // Cancels a booking if the seat is currently reserved
    void cancelSeat(int row, int seat) {
        if (row < 0 || row >= ROWS || seat < 0 || seat >= SEATS_PER_ROW) {
            cout << "Invalid seat location.\n";
            return;
        }
        if (!seats[row][seat]) {
            cout << "Seat is not currently booked.\n";
        } else {
            seats[row][seat] = false;
            cout << "Seat successfully cancelled.\n";
        }
    }
};

int main() {
    ConcertTicketSystem system;
    const string filename = "seats_layout.txt";
    system.loadSeatsFromFile(filename);

    int choice;
    char rowChar;
    int seatNum;

    // Menu creation
    do {
        cout << "\n========= Concert Ticket System =========\n";
        cout << "1. View Seats\n";
        cout << "2. Book Seat\n";
        cout << "3. Cancel Seat\n";
        cout << "4. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                system.displaySeatLayout();
                break;
            case 2:
                cout << "Enter row letter (A-E): ";
                cin >> rowChar;
                cout << "Enter seat number (1-10): ";
                cin >> seatNum;
                system.bookSeat(toupper(rowChar) - 'A', seatNum - 1);
                break;
            case 3:
                cout << "Enter row letter (A-E): ";
                cin >> rowChar;
                cout << "Enter seat number (1-10): ";
                cin >> seatNum;
                system.cancelSeat(toupper(rowChar) - 'A', seatNum - 1);
                break;
            case 4:
                system.saveSeatsToFile(filename);
                cout << "Exiting and saving data...\n";
                break;
            default:
                cout << "Invalid option. Try again.\n";
        }
    } while (choice != 4);

    return 0;
}
