import matplotlib

# Use non-interactive backend for headless environments
matplotlib.use("Agg")
import matplotlib.pyplot as plt
import pandas as pd

# Load CSV
df = pd.read_csv("timecompariasion.csv")

# Filter DP and Knapsack
dp = df[df["method"] == "DP"]
knap = df[df["method"] == "Knapsack"]

# ----- Plot Time vs Problem Size -----
plt.figure(figsize=(10, 6))
plt.plot(dp["problem_size"], dp["time_ns"], marker="o", label="DP")
plt.plot(knap["problem_size"], knap["time_ns"], marker="s", label="Knapsack")

plt.xlabel("Problem Size (number of items)")
plt.ylabel("Time (ns)")
plt.title("Knapsack: DP vs Branchandbound")
plt.legend()
plt.grid(True)
plt.tight_layout()
plt.savefig("knapsack_time_comparison.png")  # Save to file
plt.close()  # Close figure to free memory
