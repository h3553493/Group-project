# Group-project
Scope:
This project of ours is based upon the universe of an animation “ The promised neverland”.  We would like to design a management system for the caretakers in the story, to help them keep track of basic information and grades of the children they’re in charge of.

Background:
The story begins with 38 orphans lived in an orphanage named Grace Field House under the care of their caretaker--mama. However, one day they accidentally discovered that the true purpose of this orphanage is raising them as high quality food for monstrous creatures, and their “adopted” siblings were in fact “shipmented” to these monsters as food. And as the quality of brain is a vital determinant of the value of a “food child”, the monthly test they received is to judge the development of their brain, thus the dumbest child will be shipped once they reached 6 while the smartest will be raised till 12. The caretaker of each house -- mama and sister, is in charge of the test result management, intake and shipment of the children.

Problem statement:
  The current selection system is relatively low in efficiency as Mama have to update children’s information, calculate the average grades and select the proper person by herself. Huge amount of repetitive work will cost caretaker numerous time, which could have been spent playing with children, teaching them more knowledge. So a complete children management system is integrate for Mama to relieve her from the labor.
  
Problem setting:
We need a  login system to verify the user permission (i.e. mama-- read and write, sister-- read-only)
We need a personal information management system storing children’s basic information including names, ages, codes, grades each time, which can be updated automatically by the system. The information can be viewed, searched, sorted and changed by the user.
We need a recommendation system which marks the priority of shipment of every child according to the following rules:
Children below age of 6 is not considered in the ranking.
Children between 6 to 12 is given a relative score with age possessing a weight of 20% and grade of 80%.
From low relative score to high relative score, the children are given a shipment priority from high to low.
Children reaching age of 12 is immediately raised to the highest priority.
We need a notification system which reminds Mama of the child that should be shipped in the month.
