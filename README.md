<div align="justify">

# FSPT0024 Fundamentals of Programming - Final Project
This is a course in my foundation year at UTM where we learn the basics of C++ programming language. To test our knowledge and whether we know how to apply our knowledge about C++ programming language or problem-solving techniques in general, we are given a study case question and required to:
- analyze the input, process, and output
- create a flowchart
- write a C++ program
based on the study case that has been given

(This is a group project btw)

## Study Case Question
IT UTM Consultancy offers various ICT courses and has recently expanded its services to include promotional packages, multi-course registration, and detailed receipts. The company wants to develop a more advanced system to handle complex bookings and pricing. Below are some of the ICT courses available and their prices.
|                Course                | Course Code | Fee (RM) |
|--------------------------------------|:-----------:|:--------:|
| 1-AutoCAD Basic                      |      1      |  1470  |
| 2-Microsoft Excel Basic              |      2      |  525   |
| 3-Android Studio                     |      3      |  1570  |
| 4-E-Invoice Strategic Implementing   |      4      |  850   |
| 5-Analyzing Data                     |      5      |  1890  |
- We created a user interface that:
  1. Displays the available ICT courses and their fees.
  2. Allows multiple courses to be selected in one session.
  3. Applies a 10% discount for each course where more than 50 people register.
  4. Generates receipt.
- Function `calcFee()` receives the course code and number of people registering for the course. It will calculate and return the total fees.
- Function `getDisc()` receives the total fees and number of people registering, then calculates and returns the total fees after discount. A 10% discount is given if the number of people registering for the course is more than 50.
- Function `main()` prompts the user to input the course code and number of people. For every course, the number of people should be at least 30.
- Calculate the total fees using function `calcFee()`.
- Then calculate the fees after discount using function `getDisc()`.
- Finally, calculate the fees for each person needs to pay if a discount is given.
- Receipt format:
  1. Customer name.
  2. Each course name, number of participants, fees, and discount. 
  3. Final totals (subtotal, tax, grand total, amount per person).
</div>
