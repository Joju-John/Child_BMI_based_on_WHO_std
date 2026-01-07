# Child Growth Monitor

A dual-implementation (Web & C++) application for monitoring child growth based on WHO standards (0–5 years). This tool helps assess a child's nutritional status by calculating BMI and Z-Scores tailored to age and sex.

## Features

-   **WHO Standards Integration**: Uses World Health Organization data for accurate growth assessment.
-   **BMI Calculation**: Computes Body Mass Index.
-   **Z-Score Analysis**: Calculates Z-scores to determine nutritional status (e.g., Normal, Overweight, Wasted).
-   **Visual Feedback**:
    -   **Web App**: Color-coded badges and clear warnings.
    -   **CLI**: Detailed text output.

## Project Structure

-   `src/`: Source code for the Web application (JavaScript, CSS).
-   `cpp/`: Source code for the C++ command-line tool.
-   `index.html`: Entry point for the Web application.
-   `ChildGrowthMonitor.exe`: Pre-compiled executable (Windows).

## Getting Started

### Web Application

1.  Open `index.html` directly in your browser.
    -   *Note: For the best experience, use a local development server (e.g., Live Server or Vite).*

**If using a dev server:**
```bash
# Example with python
python -m http.server 
# Then visit http://localhost:8000
```

### C++ Application

You can run the pre-compiled `ChildGrowthMonitor.exe` on Windows or compile it yourself.

**To Compile (using g++):**
```bash
cd cpp
g++ main.cpp -o ChildGrowthMonitor
./ChildGrowthMonitor
```

## Usage

1.  **Select Sex**: Boy or Girl.
2.  **Enter Age**: In months (0-60).
3.  **Enter Measurements**: Weight (kg) and Height (cm).
4.  **View Results**: The app will display the BMI, Z-Score, and corresponding Status (e.g., Normal, Risk of Overweight, Obese).

## Standards Reference

This application uses the **WHO Child Growth Standards** for children aged 0 to 60 months.
-   **LMS Parameters**: Used for calculating Z-scores.
-   **Cut-offs**:
    -   `> 3 SD`: Obese
    -   `> 2 SD`: Overweight
    -   `> 1 SD`: Possible risk of overweight
    -   `>= -2 SD`: Normal
    -   `>= -3 SD`: Wasted
    -   `< -3 SD`: Severely Wasted
