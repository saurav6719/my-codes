import java.sql.*;  // Import the SQL package for database connectivity

public class EmployeeDatabaseHandler {
    public static void main(String[] args) {
        // Define database connection details
        final String dbUrl = "jdbc:mysql://localhost:3306/CompanyDB";
        final String dbUser = "admin";
        final String dbPass = "Saurav@3456";

        try (Connection conn = DriverManager.getConnection(dbUrl, dbUser, dbPass);
             Statement stmt = conn.createStatement()) {

            // Step 1: Fetch and display employee details
            String fetchQuery = "SELECT * FROM staff";
            ResultSet resultSet = stmt.executeQuery(fetchQuery);
            System.out.println("Employees in the system:");

            while (resultSet.next()) {
                System.out.println(resultSet.getInt("staff_id") + " | " +
                                   resultSet.getString("full_name") + " | " +
                                   resultSet.getString("job_title") + " | " +
                                   resultSet.getDouble("monthly_salary") + " | " +
                                   resultSet.getString("team"));
            }

            // Step 2: Update salary for an employee (ID = 2)
            String updateSalaryQuery = "UPDATE staff SET monthly_salary = monthly_salary * 1.15 WHERE staff_id = 2";
            int updatedRows = stmt.executeUpdate(updateSalaryQuery);
            System.out.println(updatedRows + " record(s) updated with new salary.");

            // Step 3: Insert a new employee record
            String insertEmployeeQuery = "INSERT INTO staff (staff_id, full_name, job_title, monthly_salary, team) " +
                                         "VALUES (4, 'Michael Brown', 'UX Designer',70000.0, 'Design')";
            int insertedRows = stmt.executeUpdate(insertEmployeeQuery);
            System.out.println(insertedRows + " new record(s) inserted into the database.");

            // Step 4: Delete an employee record (ID = 4)
            String deleteEmployeeQuery = "DELETE FROM staff WHERE staff_id = 4";
            int deletedRows = stmt.executeUpdate(deleteEmployeeQuery);
            System.out.println(deletedRows + " record(s) deleted.");

            // Step 5: Fetch and display updated employee details
            resultSet = stmt.executeQuery(fetchQuery);
            System.out.println("\nUpdated list of employees:");

            while (resultSet.next()) {
                System.out.println(resultSet.getInt("staff_id") + " | " +
                                   resultSet.getString("full_name") + " | " +
                                   resultSet.getString("job_title") + " | " +
                                   resultSet.getDouble("monthly_salary") + " | " +
                                   resultSet.getString("team"));
            }

        } catch (SQLException e) {
            e.printStackTrace();  // Print error stack trace for debugging
        }
    }
}
