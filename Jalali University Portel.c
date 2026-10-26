                  /* 
                          Login Credentials

               Portal  	:   Username/Roll No : 	Password
             
               Student  :	  101 to 105       :   stu123
               Faculty	:   faculty	         :   admin123
              */

#include <stdio.h>
#include <string.h>

struct Student
{
    int rollNo;
    char name[30];
    float marks;
    float attendance;
};

struct Student students[5] =
{
    {101, "Ali", 85, 90},
    {102, "Ahmed", 78, 82},
    {103, "Usman", 92, 95},
    {104, "Hamza", 65, 75},
    {105, "Bilal", 88, 87}
};

int totalStudents = 5;

/* Student Login */
int studentLogin(void)
{
    int id, i = 0;
    char password[30];

    printf("\n===== JALALI STUDENT LOGIN =====\n\n");
    printf("Enter Roll Number: ");
    scanf("%d", &id);

    printf("Enter Password: ");
    scanf("%29s", password);

    if (strcmp(password, "stu123") == 0)
    {
        while (i < totalStudents)
        {
            if (students[i].rollNo == id)
            {
                printf("\nLogin Successful!\n");
                return i;
            }
            i++;
        }
    }

    printf("Invalid ID or Password!\n");
    return -1;
}

/* Faculty Login */
int facultyLogin(void)
{
    char username[30], password[30];

    printf("\n\n===== JALALI FACULTY LOGIN =====\n\n");
    printf("Enter Username: ");
    scanf("%29s", username);

    printf("Enter Password: ");
    scanf("%29s", password);

    if (strcmp(username, "faculty") == 0 &&
        strcmp(password, "admin123") == 0)
    {
        printf("\nFaculty Login Successful. \n");
        return 1;
    }

    printf("Invalid Faculty Credentials !\n");
    return 0;
}

/* Attendance */
void viewAttendance(int i)
{
    printf("\nStudent: %s\n", students[i].name);
    printf("Attendance: %.2f%%\n",
           students[i].attendance);
}

/* Marks and Grade */
void viewMarks(int i)
{
    printf("\nStudent: %s\n", students[i].name);
    printf("Marks: %.2f / 100\n", students[i].marks);

    if (students[i].marks >= 85)
        printf("Grade: A\n");
    else if (students[i].marks >= 70)
        printf("Grade: B\n");
    else if (students[i].marks >= 50)
        printf("Grade: C\n");
    else
        printf("Grade: F\n");
}

/* Course Content */
void courseContent(void)
{
    printf("\n===== COURSE CONTENT =====\n\n");
    printf("1. Introduction to Programming\n");
    printf("2. Variables and Data Types\n");
    printf("3. If-Else and Switch\n");
    printf("4. Loops and Arrays\n");
    printf("5. Functions and Structures\n");
}

/* Assignments */
void viewAssignments(void)
{
    printf("\n===== ASSIGNMENTS =====\n\n");
    printf("1. Program Using Arrays\n");
    printf("2. Program Using Functions\n");
    printf("3. Student Record System\n");
}

/* Quiz */
void viewQuiz(void)
{
    int answer;

    printf("\n===== C PROGRAMMING QUIZ =====\n\n");
    printf("What is the format specifier for int?\n");
    printf("1. %%f\n");
    printf("2. %%d\n");
    printf("3. %%c\n");
    printf("4. %%s\n");
    printf("Enter Answer: ");
    scanf("%d", &answer);

    if (answer == 2)
        printf("Correct Answer!\n");
    else
        printf("Wrong Answer! Correct option is 2.\n");
}

/* Timetable */
void viewTimetable(void)
{
    printf("\n===== TIMETABLE =====\n\n");
    printf("Monday    - Programming Fundamentals\n");
    printf("Tuesday   - Discrete Structures\n");
    printf("Wednesday - OOP\n");
    printf("Thursday  - Calculus\n");
    printf("Friday    - Programming Lab\n");
}

/* Faculty Details */
void viewFaculty(void)
{
    printf("\n===== FACULTY DETAILS =====\n\n");
    printf("Programming: Faculty Member 1\n");
    printf("Discrete Structures: Faculty Member 2\n");
    printf("OOP: Faculty Member 3\n");
}

/* My Project */
void viewProject(void)
{
    printf("\n===== MY PROJECT =====\n\n");
    printf("Project: JALALI University Portal\n");
    printf("Language: C Programming\n");
    printf("Developer: Jalali\n");
    printf("Features: Login, Marks, Attendance, Courses\n");
}

/* Shared Student Features */
void studentMenu(int i)
{
    int choice = -1;

    while (choice != 0)
    {
        printf("\n===== JALALI STUDENT PORTAL =====\n\n");
        printf("Welcome, %s!\n", students[i].name);

        printf("1. View Attendance\n");
        printf("2. View Marks and Grade\n");
        printf("3. Course Content\n");
        printf("4. Assignments\n");
        printf("5. Quiz\n");
        printf("6. Timetable\n");
        printf("7. Faculty Details\n");
        printf("8. My Project\n");
        printf("0. Logout\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                viewAttendance(i);
                break;

            case 2:
                viewMarks(i);
                break;

            case 3:
                courseContent();
                break;

            case 4:
                viewAssignments();
                break;

            case 5:
                viewQuiz();
                break;

            case 6:
                viewTimetable();
                break;

            case 7:
                viewFaculty();
                break;

            case 8:
                viewProject();
                break;

            case 0:
                printf("Student Logged Out Successfully!\n");
                break;

            default:
                printf("Invalid Choice!\n");
        }
    }
}

/* View All Student Records */
void viewAllStudents(void)
{
    int i = 0;

    printf("\n===== JALALI STUDENT RECORDS =====\n\n");

    printf("%-10s %-15s %-10s %-10s\n",
           "Roll No", "Name", "Marks", "Attendance");

    while (i < totalStudents)
    {
        printf("%-10d %-15s %-10.2f %-10.2f\n",
               students[i].rollNo,
               students[i].name,
               students[i].marks,
               students[i].attendance);

        i++;
    }
}

/* Update Marks */
void updateMarks(void)
{
    int id, i = 0, found = 0;
    float marks;

    printf("Enter Student Roll Number: ");
    scanf("%d", &id);

    while (i < totalStudents)
    {
        if (students[i].rollNo == id)
        {
            printf("Enter Marks (0-100): ");
            scanf("%f", &marks);

            if (marks >= 0 && marks <= 100)
            {
                students[i].marks = marks;
                printf("Marks Updated Successfully!\n");
            }
            else
            {
                printf("Invalid Marks!\n");
            }

            found = 1;
            break;
        }

        i++;
    }

    if (found == 0)
        printf("Student Not Found!\n");
}

/* Update Attendance */
void updateAttendance(void)
{
    int id, i = 0, found = 0;
    float attendance;

    printf("Enter Student Roll Number: ");
    scanf("%d", &id);

    while (i < totalStudents)
    {
        if (students[i].rollNo == id)
        {
            printf("Enter Attendance (0-100): ");
            scanf("%f", &attendance);

            if (attendance >= 0 && attendance <= 100)
            {
                students[i].attendance = attendance;
                printf("Attendance Updated Successfully!\n");
            }
            else
            {
                printf("Invalid Attendance!\n");
            }

            found = 1;
            break;
        }

        i++;
    }

    if (found == 0)
        printf("Student Not Found!\n");
}

/* HR Information */
void hrInformation(void)
{
    printf("\n===== JALALI HR INFORMATION =====\n\n");
    printf("1. Faculty Employee Records\n");
    printf("2. HR Department Information\n");
    printf("Contact the university HR department for details.\n");
}

/* Settings */
void portalSettings(void)
{
    printf("\n===== JALALI PORTAL SETTINGS =====\n\n");
    printf("1. Account Settings\n");
    printf("2. System Configuration\n");
    printf("Settings menu opened.\n");
}

/* Faculty Portal */
void facultyMenu(void)
{
    int choice = -1;

    while (choice != 0)
    {
        printf("\n\n===== JALALI FACULTY PORTAL =====\n\n");

        printf("1.  Access Student Portal\n");
        printf("2.  View All Students\n");
        printf("3.  Update Student Marks\n");
        printf("4.  Manage Attendance\n");
        printf("5.  Course Content\n");
        printf("6.  Assignments\n");
        printf("7.  Quiz\n");
        printf("8.  Timetable\n");
        printf("9.  Student Report\n");
        printf("10. HR Information\n");
        printf("11. Settings\n");
        printf("0.  Logout\n");
        printf("Enter Choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
            {
                int i = studentLogin();

                if (i != -1)
                    studentMenu(i);

                break;
            }

            case 2:
                viewAllStudents();
                break;

            case 3:
                updateMarks();
                break;

            case 4:
                updateAttendance();
                break;

            case 5:
                courseContent();
                break;

            case 6:
                viewAssignments();
                break;

            case 7:
                viewQuiz();
                break;

            case 8:
                viewTimetable();
                break;

            case 9:
                viewAllStudents();
                break;

            case 10:
                hrInformation();
                break;

            case 11:
                portalSettings();
                break;

            case 0:
                printf("Faculty Logged Out Successfully.\n");
                break;

            default:
                printf("Invalid Choice ! \n");
        }
    }
}

/* Main Function */
int main(void)
{
    int choice = -1;

    while (choice != 0)
    {
        printf("\n====================================\n\n");
        printf("       JALALI UNIVERSITY PORTAL\n\n");
        printf("====================================\n\n");

        printf("1. Student Login\n");
        printf("2. Faculty Login\n");
        printf("0. Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
            {
                int i = studentLogin();

                if (i != -1)
                    studentMenu(i);

                break;
            }

            case 2:
                if (facultyLogin())
                    facultyMenu();

                break;

            case 0:
                printf("Thank You for Using JALALI Portal !\n");
                break;

            default:
                printf("Invalid Choice !\n");
        }
    }

    return 0;
}
