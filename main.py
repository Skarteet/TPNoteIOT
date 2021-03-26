# pip3 install google-cloud-firestore
from google.cloud import firestore
import threading
import datetime
import serial

# init State : change mode LED
state = "1"

# Create an Event for notifying main thread
callback_done_firestore = threading.Event()

# Add a new client
db = firestore.Client()

# Create a callback on_snapshot function to capture changes
def on_snapshot(doc_snapshot, changes, read_time):
    global state
    for doc in doc_snapshot:
        print(f'Received document snapshot: {doc.id}')
        print(doc.to_dict())
        state = doc.to_dict().get("state", "0")

    callback_done_firestore.set()

# Add ref to document
temp_ref = db.collection('temp').document('w0DEdZew1ZKa0LCBE4lU')

# Init snapshot temp
doc_watch = temp_ref.on_snapshot(on_snapshot)

# Connect to Arduino
ser = serial.Serial('/dev/ttyACM0',9600)

# Start program
while True:
    read_serial=ser.readline()

    # Serialize data
    data = read_serial.decode()
    print("data :", data)
    data = data.replace("\r\n", "").split(',')

    # Data type captor
    if len(data) > 1:
        # Add data in collection
        print("captor :", data)
        temp_ref.collection('data').document().set({
            'date': datetime.datetime.now(),
            'temp': data[0],
            'humi': data[1],
        })

    # Send state to Arduino
    print("state :", state)
    ser.write((state + "\n").encode())