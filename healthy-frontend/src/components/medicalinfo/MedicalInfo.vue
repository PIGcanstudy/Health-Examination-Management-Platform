<template>
  <div class="container">
    <!-- 人脸采集 -->
    <div class="shoting">
      <!-- 激活弹窗 -->
      <div class="pic" style="cursor: pointer; padding: 0 20px 20px 20px">
        <div class="pic-box">
          <img src="@/assets/medicalinfo/pic-icon.svg" style="display: block; margin: 0 auto; padding-top: 40px" />
          <span style="height: auto; line-height: 0; margin-top: 30px; color: rgb(41, 136, 243)">人脸采集</span>
        </div>
      </div>
      <!-- temp(当封装好弹窗组件后，调用弹窗组件实现上传头像) -->
      <el-upload action="">
        <el-button type="">点此上传</el-button>
      </el-upload>
    </div>
    <!-- 右侧卡片 -->
    <div class="right-card">
      <!-- 完成进度(登记、在检、总检、已完成) -->
      <div class="step">
        <ul>
          <li v-for="(item, index) in data" :key="index">
            <div v-if="index == 0">
              <img src="@/assets/medicalinfo/start_check.png" v-if="type > 0" />
              <img src="@/assets/medicalinfo/start_nomal.png" v-else />
            </div>
            <div v-if="index > 0 && index < data.length - 1">
              <img src="@/assets/medicalinfo/mid_check.png" v-if="type > 1 && index < type" />
              <img src="@/assets/medicalinfo/mid_nomal.png" v-else />
            </div>
            <div v-if="index == data.length - 1">
              <img src="@/assets/medicalinfo/end_check.png" v-if="type == data.length" />
              <img src="@/assets/medicalinfo/end_nomal.png" v-else />
            </div>
            <span>{{ item }}</span>
          </li>
        </ul>
      </div>
      <!-- 个人信息 -->
      <el-form ref="form" label-width="80px" :model="personInfo" :rules="rules" class="flex-form">
        <el-form-item label="体检编号" prop="physical_id">
          <el-input v-model.trim="personInfo.physical_id" autocomplete="off" disabled />
        </el-form-item>
        <el-form-item label="身份证号" prop="id_card">
          <el-input v-model.trim="personInfo.id_card" autocomplete="off" readonly />
        </el-form-item>
        <el-form-item label="姓名" prop="person_name">
          <el-input v-model.trim="personInfo.person_name" autocomplete="off" readonly />
        </el-form-item>
        <el-form-item label="性别" prop="sex">
          <el-input v-model.trim="personInfo.sex" autocomplete="off" readonly />
        </el-form-item>
        <el-form-item label="年龄" prop="age">
          <el-input v-model.trim="personInfo.age" autocomplete="off" readonly />
        </el-form-item>
        <el-form-item label="体检类型" prop="physical_type">
          <el-input v-model.trim="personInfo.physical_type" autocomplete="off" readonly />
        </el-form-item>
        <el-form-item label="联系电话" prop="mobile">
          <el-input v-model.trim="personInfo.mobile" autocomplete="off" readonly />
        </el-form-item>
        <el-form-item label="单位名称" prop="unit_name">
          <el-input v-model.trim="personInfo.unit_name" autocomplete="off" readonly />
        </el-form-item>
        <el-form-item label="婚姻状态" prop="marry_type">
          <el-select v-model.trim="personInfo.marry_type" placeholder="请选择">
            <el-option label="未婚" value="未婚" />
            <el-option label="已婚" value="已婚" />
            <el-option label="离异" value="离异" />
          </el-select>
        </el-form-item>
        <el-form-item label="分组名称" prop="createTime">
          <el-select v-model.trim="personInfo.createTime" placeholder="请选择">
            <el-option label="男" value="男" />
            <el-option label="女" value="女" />
          </el-select>
        </el-form-item>
      </el-form>
    </div>
  </div>
</template>
<script>
export default {
  name: 'medicalinfo',
  data() {
    return {
      /* 当前流程(登记、在检查...) */
      data: this.arr,
      type: this.index,
      /* 个人信息表单 */
      // 表单数据
      personInfo: {
        physical_id: '2202401120016',
        id_card: '510521199304017011',
        person_name: 'test-rom',
        sex: '男',
        age: '30',
        physical_type: '健康体检',
        mobile: '18980504604',
        unit_name: 'test-rom',
        marry_type: '',
        createTime: ''
      },
      // 必须填写的部分
      rules: {
        id_card: [{ required: true }],
        person_name: [{ required: true }],
        sex: [{ required: true }],
        age: [{ required: true }],
        physical_type: [{ required: true }]
      },
      title: ''
    }
  },
  // 当前流程数据
  props: {
    index: {
      type: Number,
      default: 1
    },
    arr: {
      type: Array,
      default: () => {
        return ['登记', '在检', '总检', '已完成']
      }
    }
  },
  // 监听数据，当更新时才执行
  watch: {
    index(val) {
      this.type = val
    }
  },
  methods: {}
}
</script>
<!-- 局内样式 -->
<style scoped>
/* 控制整体布局 */
.container {
  display: flex;
  justify-content: space-between;
}
.shoting .right-card {
  flex: 1; /* 调整 flex 基础大小，或使用具体的宽度，例如 flex: 0 0 300px; */
}
.shoting {
  flex: 1 1 12%; /* 让.shoting占据更多的空间 */
}
.right-card {
  flex: 1 1 90%; /* 让.right-card占据更多的空间 */
}
/* 人脸采集 */
.pic-box {
  border: 1px dashed #2988f3;
  width: 130px;
  height: 150px;
  text-align: center;
}
/* 当前流程(登记、在检查...) */
.step {
  ul {
    list-style: none;
    display: flex;
    padding: 0;
    margin: 0;

    li {
      position: relative;
      width: 100px;
      height: 30px;
      margin-right: -10px;

      span {
        position: absolute;
        top: 50%;
        left: 50%;
        transform: translate(-50%, -50%);
        z-index: 10;
        white-space: nowrap;
        color: #fff;
        font-size: 13px;
        font-weight: 600;
      }
    }
  }
}
/* 个人信息表单 */
.flex-form {
  padding-top: 20px;
  display: flex;
  flex-wrap: wrap; /* 允许表单项换行 */
  align-items: flex-start; /* 对齐表单项 */
}

.flex-form .el-form-item {
  flex: 1 1 200px; /* 每个表单项的基础大小和增长因子 */
}
</style>
<!-- 全局样式 -->
<style>
.el-input {
  width: 180px;
}
</style>
