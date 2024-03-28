import pandas as pd

def count_salary_categories(accounts: pd.DataFrame) -> pd.DataFrame:
    labels = ["Low Salary", "Average Salary", "High Salary"]
    bins = [float("-inf"), 20000, 50001, float("inf")]
    categorized_incomes = pd.cut(accounts.income, bins, right=False, labels=labels)
    counts = categorized_incomes.value_counts()
    categories = pd.DataFrame({
        "category": counts.index,
        "accounts_count": counts.values,
    })
    return categories