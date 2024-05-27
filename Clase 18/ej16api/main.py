from fastapi import FastAPI, HTTPException
from pymongo import MongoClient
from pydantic import BaseModel

client = MongoClient("mongodb://localhost:27017/")
db = client["POO"]
collection = db["POO"]

app = FastAPI()


class User(BaseModel):
    name: str
    family_name: str
    user: str
    password: str


@app.get("/users/")
async def get_all_users():
    cursor = collection.find()
    users = []
    for user in cursor:
        user["_id"] = str(user["_id"])
        users.append(user)
    return users


@app.post("/validate-user")
async def validate_user(username: str, password: str):
    query = {"user": username, "password": password}
    result = collection.find_one(query)

    if result is None:
        raise HTTPException(status_code=401, detail="denegado")

    return {"success": "true", "user": result["user"], "password": result["password"]}
