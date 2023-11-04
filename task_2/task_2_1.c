#include "task_2.h"

int main() {
    initscr();
    phoneBook profile = {0};
    int cntSocial = 1;
    char ch = '0';
    while(ch != '5') {
        showMenu();
        switch(ch) {
            case '1':
                printProfile(&profile, cntSocial);
                break;
            case '2':
                addProfile(&profile, &cntSocial);
                break;
            case '3':
                editProfile(&profile, cntSocial);
                break;
            case '4':
                deleteProfile(&profile, cntSocial);
                break;
        }
        ch = getch();
        refresh();
    }
    endwin();
    return 0;
}

void showMenu() {
    clear();
    printw("Menu:\n");
    printw("1. Show phone book\n");
    printw("2. Add profile in phone book\n");
    printw("3. Edit profile in phone book\n");
    printw("4. Delete profile in phone book\n");
    printw("5. Exit\n\n");
}

void addProfile(phoneBook *profile, int *cntSocial) {
    printw("Enter lastname: ");
    scanw("%s", profile->lastName);
    printw("Enter firstname: ");
    scanw("%s", profile->firstName);
    printw("Enter fathername: ");
    scanw("%s", profile->fatherName);
    printw("Enter job: ");
    scanw("%s", profile->job);
    printw("Enter jobtitle: ");
    scanw("%s", profile->jobTitle);
    printw("Enter phone: ");
    scanw("%ld", &profile->phone);
    printw("Enter email: ");
    scanw("%s", profile->email);
    printw("How many social links entered?: ");
    scanw("%d", cntSocial);
    for(int i = 0; i < *cntSocial; i++) {
        printw("Enter %d sociallink: ", i + 1);
        scanw("%s", profile->socialLinks[i]);
    }
}

void printProfile(phoneBook *profile, int cntSocial) {
    printw("Lastname: %s\n", profile->lastName);
    printw("Firstname: %s\n", profile->firstName);
    printw("Fathertname: %s\n", profile->fatherName);
    printw("Job: %s\n", profile->job);
    printw("Jobtitle: %s\n", profile->jobTitle);
    printw("Phone: %ld\n", profile->phone);
    printw("Email: %s\n", profile->email);
    for(int i = 0; i < cntSocial; i++)
        printw("Sociallink %d: %s\n", i + 1, profile->socialLinks[i]);
}

void deleteProfile(phoneBook *profile, int cntSocial) {
    strncpy(profile->lastName, "", N);
    strncpy(profile->firstName, "", N);
    strncpy(profile->fatherName, "", N);
    strncpy(profile->job, "", N);
    strncpy(profile->jobTitle, "", N);
    profile->phone = 0;
    strncpy(profile->email, "",N);
    for(int i = 0; i < cntSocial; i++)
        strncpy(profile->socialLinks[i], "", N);
    printw("Delete profile complete\n");
}

void editProfile(phoneBook *profile, int cntSocial) {
    printw("Enter number of edit:\n");
    printw("1. Lastname\n");
    printw("2. Firstname\n");
    printw("3. Fathertname\n");
    printw("4. Job\n");
    printw("5. Jobtitle\n");
    printw("6. Phone\n");
    printw("7. Email\n");
    printw("8. Sociallinks\n");
    char ch = '0';
    switch(ch = getch()) {
        case '1':
            printw("\nEnter lastname: ");
            scanw("%s", profile->lastName);
            break;
        case '2':
            printw("\nEnter firstname: ");
            scanw("%s", profile->firstName);
            break;
        case '3':
            printw("\nEnter fathername: ");
            scanw("%s", profile->fatherName);
            break;
        case '4':
            printw("\nEnter job: ");
            scanw("%s", profile->job);
            break;
        case '5':
            printw("\nEnter jobtitle: ");
            scanw("%s", profile->jobTitle);
            break;
        case '6':
            printw("\nEnter phone: ");
            scanw("%ld", &profile->phone);
            break;
        case '7':
            printw("\nEnter email: ");
            scanw("%s", profile->email);
            break;
        case '8':
            printw("\n");
            for(int i = 0; i < cntSocial; i++) {
                printw("Enter %d social link: ", i + 1);
                scanw("%s", profile->socialLinks[i]);
            }
            break;
    }
}