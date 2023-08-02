#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int bookAppointment()
{
    system("cls");

    cout << "\n ----- Book your appointment for a particular time slot ---- \n";
    cout << "\n ----- Available slots are ---- \n";

    ifstream appointmentFile;
    appointmentFile.open("appointments.dat");

    int startingHour = 8;

    int timeSlots[13] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int recordFound = 0;

    if (appointmentFile)
    {
        string line;
        char timeSlotChar = 'A';
        int currentHour = 9;

        while (getline(appointmentFile, line))
        {
            char temp = line[0];
            int index = (temp - 65);
            timeSlots[index] = 1;
            recordFound = 1;
        }

        if (recordFound == 1)
        {
            cout << "\n Appointment List by Hours:";
            char timeSlotChar = 'A';
            int hours = 9;
            for (int i = 0; i <= 12; i++)
            {
                if (i == 0)
                {
                    if (timeSlots[i] == 0)
                        cout << "\n " << timeSlotChar << "-> 0" << hours << " - Available";
                    else
                        cout << "\n " << timeSlotChar << "-> 0" << hours << " - Booked";
                }
                else
                {
                    if (timeSlots[i] == 0)
                        cout << "\n " << timeSlotChar << "->" << hours << " - Available";
                    else
                        cout << "\n " << timeSlotChar << "->" << hours << " - Booked";
                }
                hours++;
                timeSlotChar++;
            }
        }

        appointmentFile.close();
    }

    if (recordFound == 0)
    {
        cout << "\n Appointment Available for the following hours :";
        char timeSlotChar = 'A';
        for (int i = 9; i <= 21; i++)
        {
            if (i == 9)
                cout << "\n " << timeSlotChar << " -> 0" << i << " - Available";
            else
                cout << "\n " << timeSlotChar << " -> " << i << " - Available";
            timeSlotChar++;
        }
    }

    char selectedTimeSlot;
    cout << "\n\n Choose your slot: ";
    cin >> selectedTimeSlot;

    if (!(selectedTimeSlot >= 'A' && selectedTimeSlot <= 'Z'))
    {
        cout << "\n Error : Invalid Selection";
        cout << "\n Please select the correct value from the menu A- Z";
        cout << "\n Press any key to continue";
        getchar();
        getchar();
        system("cls");
        bookAppointment();
    }

    int timeSlotIndex = (selectedTimeSlot - 65);
    int isBooked = 1;
    if (timeSlots[timeSlotIndex] == 0)
        isBooked = 0;

    if (isBooked == 1)
    {
        cout << "\n Error : This appointment slot is already booked";
        cout << "\n Please select a different slot time !!";
        cout << "\n Press any key to continue!!";
        getchar();
        getchar();
        system("cls");
        bookAppointment();
    }

    string name;
    cout << "\n Enter your Name:";
    cin >> name;

    ofstream out;
    out.open("appointments.dat", ios::app);

    if (out)
    {
        out << selectedTimeSlot << ":" << name.c_str() << "\n";
        out.close();
        cout << "\n Appointment is Successfully Booked for Hours : " << (selectedTimeSlot - 65) + 9 << " !!";
    }
    else
    {
        cout << "\n Error while saving booking";
    }

    cout << "\n Please any key to continue..";
    getchar();
    getchar();
    return 0;
}

int listExistingAppointments()
{
    system("cls");

    cout << "\n ----- List of Available Appointments ---- \n";

    ifstream appointmentFile;
    appointmentFile.open("appointments.dat");

    int startingHour = 8;

    int timeSlots[13] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int recordFound = 0;

    if (appointmentFile)
    {
        string line;
        char timeSlotChar = 'A';
        int currentHour = 9;

        while (getline(appointmentFile, line))
        {
            char temp = line[0];
            int index = (temp - 65);
            timeSlots[index] = 1;
            recordFound = 1;
        }

        if (recordFound == 1)
        {
            cout << "\n Appointment List by hours:";
            char timeSlotChar = 'A';
            int hours = 9;
            for (int i = 0; i <= 12; i++)
            {
                if (i == 0)
                {
                    if (timeSlots[i] == 0)
                        cout << "\n " << timeSlotChar << "-> 0" << hours << " - Available";
                    else
                        cout << "\n " << timeSlotChar << "-> 0" << hours << " - Booked";
                }
                else
                {
                    if (timeSlots[i] == 0)
                        cout << "\n " << timeSlotChar << "->" << hours << " - Available";
                    else
                        cout << "\n " << timeSlotChar << "->" << hours << " - Booked";
                }
                hours++;
                timeSlotChar++;
            }
        }

        appointmentFile.close();
    }

    if (recordFound == 0)
    {
        cout << "\n Appointment Available for following hours :";
        char timeSlotChar = 'A';
        for (int i = 9; i <= 21; i++)
        {
            if (i == 9)
                cout << "\n " << timeSlotChar << " -> 0" << i << " - Available";
            else
                cout << "\n " << timeSlotChar << " -> " << i << " - Available";
            timeSlotChar++;
        }
    }

    ofstream out;
    out.open("appointments.dat", ios::app);

    cout << "\n Please any key to continue..";
    getchar();
    getchar();
    return 0;
}

int main(int argc, char **argv)
{
    while (true)
    {
        system("cls");
        cout << "\t\tDoctor Appointment Booking System\n";
        cout << "----------------------------------------\n\n";

        cout << "  1. Book an Appointment\n";
        cout << "  2. Check All Existing Appointments\n";
        cout << "  0. Exit Now \n";
        int choice;

        cout << "\n Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            bookAppointment();
            break;
        case 2:
            listExistingAppointments();
            break;
        case 0:
            while (true)
            {
                system("cls");
                cout << "\n Are you sure you want to exit? y | n \n";
                char ex;
                cin >> ex;
                if (ex == 'y' || ex == 'Y')
                    exit(0);
                else if (ex == 'n' || ex == 'N')
                {
                    break;
                }
                else
                {
                    cout << "\n Invalid choice !!!";
                    getchar();
                }
            }
            break;

        default:
            cout << "\n Invalid choice. Enter again ";
            getchar();
        }
    }
    return 0;
}
