import pandas as pd

def department_highest_salary(employee: pd.DataFrame, department: pd.DataFrame) -> pd.DataFrame:
    highest_salary = employee.groupby("departmentId")["salary"].max()
    merged_salary = pd.merge(employee, highest_salary, how="inner", on=["departmentId", "salary"])
    merged_department = pd.merge(merged_salary, department, how="inner", left_on="departmentId", right_on="id")
    return merged_department[["name_y", "name_x", "salary"]].rename(columns={
        "name_y": "Department",
        "name_x": "Employee",
        "salary": "Salary",
    })