import pandas as pd

def calculate_special_bonus(employees: pd.DataFrame) -> pd.DataFrame:
    employees["bonus"] = 0
    lucky_employees = (employees["name"].str.startswith("M") == False) & (employees["employee_id"] % 2 == 1)
    employees.loc[lucky_employees, "bonus"] = employees["salary"]
    return employees[["employee_id", "bonus"]].sort_values(by="employee_id")