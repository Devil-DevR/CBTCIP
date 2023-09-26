# CBTCIP
Cyberbytes Technologies Internship Tasks
SRMS (Student Record Management System). It allows users to add, delete, search, update, display student records, and save the records to a file. Here's an overview of how the program works:

1. **Data Structure**: The program uses a `struct` named `student` to store information about each student, including their roll number, name, section, and CGPA.

2. **Vector**: The student records are stored in a `vector` of `student` objects called `studentrecord`.

3. **User Input Validation**: The program uses the `getIntInput` and `getFloatInput` functions to validate user input for integers and floating-point numbers, respectively.

4. **Menu System**: It provides a menu-driven interface for users to perform various operations on student records, such as adding, deleting, searching, updating, displaying, and ranking.

5. **Sorting**: The `selectionSort` function is used to sort student records based on roll number and CGPA.

6. **File Handling**: The program can save student records to a file named "StudentRecord.txt" using the `saveRecord` function.

7. **Main Loop**: The program uses a `do-while` loop to continuously display the main menu and execute the selected operation until the user chooses to exit (option 999).

8. **Functionality**: Users can interact with the program to perform actions like adding a new student, deleting a student, searching for a student by roll number, updating a student's details, displaying all student records, ranking students by CGPA, and saving records to a file.

9. **Input/Output Formatting**: The program uses `setw` and `left` manipulators to format the display of student records and menus for better readability.

Overall, your program provides a comprehensive student record management system with validation, sorting, and file handling capabilities. Users can easily manage and access student information through the menu-driven interface.
