# SOLID Principles

=> The SOLID principles are five essential guidelines that enhance software design, making code more maintainable and scalable.

    1: The SOLID principles help in enhancing loose coupling. Loose coupling means a group of classes are less dependent on one another.
    2: Loose coupling helps in making code more reusable, maintainable, flexible and stable. Now let's discuss one by one these principles...
    3: Loosely coupled classes minimize changes in your code when some changes are required in some other code.

=> SOLID means
S: Single Responsibility Principle (SRP)
O: Open - Close Principle (OCP)
L: Lescove Substituion Principle (LSP)
I: Interface Segrigation Princliple (ISE)
D: Dependency Inversion Principles (DIP)

# 1. Single Responsibility Principle

This principle states that "A class should have only one reason to change" which means every class should have a single responsibility or single job or single purpose. In other words, a class should have only one job or purpose within the software system.

Let's understand Single Responsibility Principle using an example:

Imagine a baker who is responsible for baking bread. The baker's role is to focus on the task of baking bread, ensuring that the bread is of high quality, properly baked, and meets the bakery's standards.

However, if the baker is also responsible for managing the inventory, ordering supplies, serving customers, and cleaning the bakery, this would violate the SRP.
Each of these tasks represents a separate responsibility, and by combining them, the baker's focus and effectiveness in baking bread could be compromised.
To adhere to the SRP, the bakery could assign different roles to different individuals or teams. For example, there could be a separate person or team responsible for managing the inventory, another for ordering supplies, another for serving customers, and another for cleaning the bakery.
