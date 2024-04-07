/**
 * Definition for Employee.
 * type Employee struct {
 *     Id int
 *     Importance int
 *     Subordinates []int
 * }
 */

func getImportance(employees []*Employee, id int) int {
    employeeMap := map[int]*Employee{}
    for _, employee := range employees {
        employeeMap[employee.Id] = employee
    }

    var sumImportance func (id int) int
    sumImportance = func (id int) int {
        totalImportance := 0
        for _, subordinate := range employeeMap[id].Subordinates {
            totalImportance += sumImportance(subordinate)
        }
        totalImportance += employeeMap[id].Importance
        return totalImportance
    }
    
    return sumImportance(id)
}