import pandas as pd

def nth_highest_salary(employee: pd.DataFrame, N: int) -> pd.DataFrame:
    salaries = employee["salary"].drop_duplicates()
    sorted = salaries.sort_values(ascending=False)    
    key = "getNthHighestSalary(" + str(N) + ")"
    if N < 1 or N > len(sorted):
        return pd.DataFrame({key: [None]})    
    nth_salary = sorted.iloc[N-1]
    return pd.DataFrame({key: [nth_salary]})
    