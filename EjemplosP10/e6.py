from datetime import timedelta, datetime

def contest_duration(name. hours=5):
    now = datetime.now()
    arrival= now + timedalta(hours=hours)
    return arrival_strftime(f"Contest{name}'s duration until: %A %H:%M")

contest_duration("EDAI")
contest_duration("CPCFI", hours=0.45)