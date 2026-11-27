import pandas as pd
from sklearn.compose import ColumnTransformer
from sklearn.linear_model import LogisticRegression
from sklearn.metrics import accuracy_score, classification_report, confusion_matrix
from sklearn.model_selection import train_test_split
from sklearn.pipeline import Pipeline
from sklearn.preprocessing import StandardScaler, OneHotEncoder


def train_model():
    data = pd.read_csv('data/shots.csv')
    shot =  data[["shooting", "distance", "pressure", "fatigue", "confidence"]]

    x = shot
    y = data["made"]

    x_train, x_test, y_train, y_test = train_test_split(x, y, test_size = 0.2, random_state = 10, )

    preprocessor = ColumnTransformer([("numeric", StandardScaler(),
                   ["shooting", "distance", "pressure", "fatigue", "confidence"]),
    ("categorical", OneHotEncoder(handle_unknown="ignore"), ["shooting"])])

    model = Pipeline([("preprocessor", preprocessor), ("classifier", LogisticRegression())])

    model.fit(x_train, y_train)

    predictions = model.predict(x_test)
    probabilities = model.predict_proba(x_test)[:, 1]

    # Evaluation
    print("\n===== MODEL EVALUATION =====")
    print(f"Accuracy: {accuracy_score(y_test, predictions):.2%}")

    print("\n===== CLASSIFICATION REPORT =====")
    print(classification_report(y_test, predictions))

    print("\n===== CONFUSION MATRIX =====")
    print(confusion_matrix(y_test, predictions))

    # Prediction comparison
    results = pd.DataFrame({
        "Actual": y_test.values,
        "Predicted": predictions,
        "Make Probability": probabilities.round(3),
        "Correct": y_test.values == predictions
    })

    print("\n===== PREDICTION RESULTS =====")
    print(results.to_string(index=False))

    return model, x_test, y_test

if __name__ == '__main__':
    train_model()