#include "task_6.h"

int main() {
    initscr();
    list *head = NULL;
    int id = 0;
    char ch = '0';
    while(ch != '5') {
        showMenu();
        switch(ch) {
            case '1':
                printList(head);
                break;
            case '2':
                head = addProfile(head);
                break;
            case '3':
                printw("Which profile by ID will we change?: ");
                scanw("%d", &id);
                head = editProfile(head, id);
                break;
            case '4':
                printw("Which profile by ID will we delete?: ");
                scanw("%d", &id);
                head = deleteElem(head, id);
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
    printw("1. Show phonebook list\n");
    printw("2. Add profile in phonebook list\n");
    printw("3. Edit profile in phonebook list\n");
    printw("4. Delete profile in phonebook list\n");
    printw("5. Exit\n\n");
}

list *addProfile(list *head) {
    phoneBook profile= {0};
    printw("Enter id: ");
    scanw("%d", &profile.id);
    printw("Enter lastname: ");
    scanw("%s", profile.lastName);
    printw("Enter firstname: ");
    scanw("%s", profile.firstName);
    printw("Enter fathername: ");
    scanw("%s", profile.fatherName);
    printw("Enter job: ");
    scanw("%s", profile.job);
    printw("Enter jobtitle: ");
    scanw("%s", profile.jobTitle);
    printw("Enter phone: ");
    scanw("%ld", &profile.phone);
    printw("Enter email: ");
    scanw("%s", profile.email);
    for(int i = 0; i < cntSocial; i++) {
        printw("Enter %d sociallink: ", i + 1);
        scanw("%s", profile.socialLinks[i]);
    }
    return addElem(head, profile);
}

void printProfile(phoneBook profile) {
    printw("ID: %d\n", profile.id);
    printw("Lastname: %s\n", profile.lastName);
    printw("Firstname: %s\n", profile.firstName);
    printw("Fathertname: %s\n", profile.fatherName);
    printw("Job: %s\n", profile.job);
    printw("Jobtitle: %s\n", profile.jobTitle);
    printw("Phone: %ld\n", profile.phone);
    printw("Email: %s\n", profile.email);
    for(int i = 0; i < cntSocial; i++)
        printw("Sociallink %d: %s\n", i + 1, profile.socialLinks[i]);
}

void deleteProfile(phoneBook *profile) {
    profile->id = 0;
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

list *editProfile(list *head, int id) {
    phoneBook profile;
    list *tmp = findInList(head, id);    
    if(tmp == NULL) return head;
    printw("Enter number of edit:\n");
    printw("1. ID\n");
    printw("2. Lastname\n");
    printw("3. Firstname\n");
    printw("4. Fathertname\n");
    printw("5. Job\n");
    printw("6. Jobtitle\n");
    printw("7. Phone\n");
    printw("8. Email\n");
    printw("9. Sociallinks\n");
    char ch = '0';
    switch(ch = getch()) {
        case '1':
            printw("\nEnter ID: ");
            scanw("%d", &profile.id);
            tmp->profile.id = profile.id;
            break;
        case '2':
            printw("\nEnter lastname: ");
            scanw("%s", profile.lastName);
            strncpy(tmp->profile.lastName, profile.lastName, N);
            break;
        case '3':
            printw("\nEnter firstname: ");
            scanw("%s", profile.firstName);
            strncpy(tmp->profile.firstName, profile.firstName, N);
            break;
        case '4':
            printw("\nEnter fathername: ");
            scanw("%s", profile.fatherName);
            strncpy(tmp->profile.fatherName, profile.fatherName, N);
            break;
        case '5':
            printw("\nEnter job: ");
            scanw("%s", profile.job);
            strncpy(tmp->profile.job, profile.job, N);
            break;
        case '6':
            printw("\nEnter jobtitle: ");
            scanw("%s", profile.jobTitle);
            strncpy(tmp->profile.jobTitle, profile.jobTitle, N);
            break;
        case '7':
            printw("\nEnter phone: ");
            scanw("%ld", &profile.phone);
            tmp->profile.phone = profile.phone;
            break;
        case '8':
            printw("\nEnter email: ");
            scanw("%s", profile.email);
            strncpy(tmp->profile.email, profile.email, N);
            break;
        case '9':
            printw("\n");
            for(int i = 0; i < cntSocial; i++) {
                printw("Enter %d social link: ", i + 1);
                scanw("%s", profile.socialLinks[i]);
                strncpy(tmp->profile.socialLinks[i], profile.socialLinks[i], N);
            }
            break;
    }
    return head;
}