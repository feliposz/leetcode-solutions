import pandas as pd

def changeDatatype(students: pd.DataFrame) -> pd.DataFrame:
    #students["grade"] = students["grade"].astype(int)
    students = students.astype({"grade": int})
    return students