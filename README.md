# Group-project
Background:
This project of ours is based upon the universe of an animation “ The promised neverland”. The story begins with 38 orphans lived peacefully in an orphanage named Grace Field House under the care of their caretaker--mama. However, one day they accidentally discovered that the true purpose of this orphanage is raising them as high quality food for monstrous creatures, and their “adopted” siblings were in fact “shipmented” to these monsters as food, thus begin their adventure of breaking away from the Grace Field House. Leaving aside the plot itself, we would like to design a management system for their caretaker to keep track of the basic information of her children and their score (as the quality of brain is a vital determinant of the value of a child,  test were held every month to decide the order of shipment).

Aim:
What our project aims to do is to create an efficient control system for Mama to easily check all the information of children on the farm including their names, ages, codes, grades every time, etc. The system can overwhelmingly relieve Mama from huge workload recording children’s grades and assessing the appropriate children to be shipped.

Functions:
The initial interface is a login page which requires the username and password to get access to the system, which comprise two kinds of user permission – Mama and Sister. Mama can read and modify all the information, while the sister has read-only permission. 
After logging in, the user has three functions to choose, Personal Information, Grade, Notification. 
The user can read the basic information of children in the Personal information part, deleting the child who has already been shipped and adding a new one.
 In the Grade part, the user can check the past grades and import new test results; the system will give weights to age and grade, and rank them of shipment priority accordingly. The ranking rule is as follows:
Children below age of 6 is not considered in the ranking.
Children between 6 to 12 is given a relative score with age possessing a weight of 20% and grade of 80%.
From low relative score to high relative score, the children are given a shipment priority from high to low.
Children reaching age of 12 is immediately raised to the highest priority.

What’s more, the system will give a recommendation list to Mama according to the rank of each child, reminding her of the children who should be shipped in the month.
Assuming the test result is imported monthly, the system will update the children’s age, average grade and ranking automatically.
