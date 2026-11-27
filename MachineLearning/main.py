from Shot import train_model
from prediction.predict import predict_shot


def main():
    model, scaler = train_model()
    probability = (predict_shot
                   (model,
                    scaler,
                    shooting=90,
                    distance=15,
                    pressure=40,
                    fatigue=20,
                    confidence=75))
    print(f"Success Probability: {probability}")
if __name__ == "__main__":
    main()