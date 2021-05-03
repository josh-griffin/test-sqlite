import { StatusBar } from "expo-status-bar";
import React from "react";
import { StyleSheet, Text, View } from "react-native";

export default function App() {
  Object.keys(global).forEach((key) => console.log("key", key));

  console.log("-------------------------------------------");
  console.log("global.test", global.test());
  console.log("global.open", global.open("josh1"));
  console.log("-------------------------------------------");

  return (
    <View style={styles.container}>
      <Text>{String(!!global.HermesInternal)}</Text>
      <Text>Open up App.js to start working on your app!</Text>
      <StatusBar style="auto" />
    </View>
  );
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    backgroundColor: "#fff",
    alignItems: "center",
    justifyContent: "center",
  },
});
