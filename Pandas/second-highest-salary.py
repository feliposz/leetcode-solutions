import pandas as pd

def second_highest_salary(employee: pd.DataFrame) -> pd.DataFrame:
    salaries = employee["salary"].drop_duplicates()
    sorted = salaries.sort_values(ascending=False)    
    key = "SecondHighestSalary"
    if len(sorted) < 2:
        return pd.DataFrame({key: [None]})    
    nth_salary = sorted.iloc[1]
    return pd.DataFrame({key: [nth_salary]})
    