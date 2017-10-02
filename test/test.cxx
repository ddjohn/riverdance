#include <iostream>

#include <gtest/gtest.h>
#include <Frame.h>
#include <SendFrame.h>
#include <ConnectFrame.h>
#include <ErrorFrame.h>
#include <ConnectedFrame.h>
#include <SubscribeFrame.h>
#include <UnsubscribeFrame.h>
#include <AckFrame.h>
#include <NackFrame.h>
#include <FrameFactory.h>

TEST(frames, Frame)
{
  Frame frame;
  frame.command = "UNKNOWN";
  frame.addHeader("key1", "value1");
  frame.addHeader("key2", "value2");
  frame.addHeader("key3", "value3");
  frame.body = "Hello WOrld";

  Frame* f = FrameFactory::parse(frame.marshall());
  EXPECT_NE(f, nullptr);

  printf("==== %s\n", f->command.c_str());
  EXPECT_STREQ(f->command.c_str(), "UNKNOWN");
//  EXPECT_STRNE(f->command.c_str(), "CONNECT");
}

TEST(frames, ConnectFrame)
{
  ConnectFrame frame("1.2", "Localhost");

  ConnectFrame* f = (ConnectFrame*)FrameFactory::parse(frame.marshall());
  EXPECT_NE(f, nullptr);
}

TEST(frames, ConnectedFrame)
{
  ConnectedFrame frame("1.2");

  ConnectedFrame* f = (ConnectedFrame*)FrameFactory::parse(frame.marshall());
  EXPECT_NE(f, nullptr);
}

TEST(frames, SendFrame)
{
  SendFrame frame("/queue/send", "message");

  SendFrame* f = (SendFrame*)FrameFactory::parse(frame.marshall());
  EXPECT_NE(f, nullptr);
}

TEST(frames, SubscribeFrame)
{
  SubscribeFrame frame("sub1", "/queue/send", SubscribeFrameAcknowledges::AUTO);

  SubscribeFrame* f = (SubscribeFrame*)FrameFactory::parse(frame.marshall());
  EXPECT_NE(f, nullptr);
}

TEST(frames, ErrorFrame)
{
  ErrorFrame frame("Message");

  ErrorFrame* f = (ErrorFrame*)FrameFactory::parse(frame.marshall());
  EXPECT_NE(f, nullptr);
}

TEST(frames, UnsubscribeFrame)
{
  UnsubscribeFrame frame("Message");

  UnsubscribeFrame* f = (UnsubscribeFrame*)FrameFactory::parse(frame.marshall());
  EXPECT_NE(f, nullptr);
}

TEST(frames, AckFrame)
{
  AckFrame frame("Message");

  AckFrame* f = (AckFrame*)FrameFactory::parse(frame.marshall());
  EXPECT_NE(f, nullptr);
}

TEST(frames, NackFrame)
{
  NackFrame frame("Message");

  NackFrame* f = (NackFrame*)FrameFactory::parse(frame.marshall());
  EXPECT_NE(f, nullptr);
}
