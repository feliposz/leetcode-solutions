import pandas as pd

def meltTable(report: pd.DataFrame) -> pd.DataFrame:
    return report.melt(id_vars="product", var_name="quarter", value_name="sales", 
        value_vars=["quarter_1", "quarter_2", "quarter_3", "quarter_4"])